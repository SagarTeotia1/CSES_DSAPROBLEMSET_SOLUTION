#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>  // Include this header for LLONG_MAX
#include <cmath>

using namespace std;

void generateSubsetSums(const vector<long long>& weights, vector<long long>& subsetSums) {
    int n = weights.size();
    int numSubsets = 1 << n; // 2^n possible subsets
    subsetSums.reserve(numSubsets);

    for (int i = 0; i < numSubsets; ++i) {
        long long sum = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                sum += weights[j];
            }
        }
        subsetSums.push_back(sum);
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<long long> weights(n);
    long long totalWeight = 0;

    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
        totalWeight += weights[i];
    }

    int mid = n / 2;
    vector<long long> weights1(weights.begin(), weights.begin() + mid);
    vector<long long> weights2(weights.begin() + mid, weights.end());

    vector<long long> subsetSums1, subsetSums2;
    generateSubsetSums(weights1, subsetSums1);
    generateSubsetSums(weights2, subsetSums2);

    sort(subsetSums1.begin(), subsetSums1.end());
    sort(subsetSums2.begin(), subsetSums2.end());

    long long minDifference = LLONG_MAX;

    for (long long sum1 : subsetSums1) {
        long long target = (totalWeight / 2) - sum1;
        auto it = lower_bound(subsetSums2.begin(), subsetSums2.end(), target);
        
        if (it != subsetSums2.end()) {
            long long sum2 = *it;
            long long currentDiff = abs(totalWeight - 2 * (sum1 + sum2));
            minDifference = min(minDifference, currentDiff);
        }
        
        if (it != subsetSums2.begin()) {
            --it;
            long long sum2 = *it;
            long long currentDiff = abs(totalWeight - 2 * (sum1 + sum2));
            minDifference = min(minDifference, currentDiff);
        }
    }

    cout << minDifference << endl;

    return 0;
}
