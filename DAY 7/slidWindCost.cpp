#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    multiset<int> low, high;
    long long lowSum = 0, highSum = 0;
    
    auto balance = [&]() {
        while (low.size() > high.size() + 1) {
            highSum += *low.rbegin();
            lowSum -= *low.rbegin();
            high.insert(*low.rbegin());
            low.erase(--low.end());
        }
        while (high.size() > low.size()) {
            lowSum += *high.begin();
            highSum -= *high.begin();
            low.insert(*high.begin());
            high.erase(high.begin());
        }
    };
    
    auto add = [&](int val) {
        if (low.empty() || val <= *low.rbegin()) {
            low.insert(val);
            lowSum += val;
        } else {
            high.insert(val);
            highSum += val;
        }
        balance();
    };
    
    auto remove = [&](int val) {
        if (low.find(val) != low.end()) {
            lowSum -= val;
            low.erase(low.find(val));
        } else {
            highSum -= val;
            high.erase(high.find(val));
        }
        balance();
    };
    
    auto getCost = [&]() {
        int median = *low.rbegin();
        return median * (long long)low.size() - lowSum + highSum - median * (long long)high.size();
    };
    
    for (int i = 0; i < k; i++) {
        add(x[i]);
    }
    
    cout << getCost();
    
    for (int i = k; i < n; i++) {
        add(x[i]);
        remove(x[i - k]);
        cout << " " << getCost();
    }
    
    cout << endl;
    return 0;
}
