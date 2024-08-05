#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> customers(m);
    multiset<int> tickets;
    
    for (int i = 0; i < n; ++i) {
        int price;
        cin >> price;
        tickets.insert(price);  // Insert ticket prices into multiset
    }
    
    for (int i = 0; i < m; ++i) {
        cin >> customers[i];
    }
    
    // Vector to store the result for each customer
    vector<int> result(m, -1);
    
    // Process each customer
    for (int i = 0; i < m; ++i) {
        int max_price = customers[i];
        
        // Use binary search to find the largest ticket price <= max_price
        auto it = tickets.upper_bound(max_price);
        
        if (it != tickets.begin()) {
            --it;  // Move to the largest valid ticket price
            result[i] = *it;
            tickets.erase(it);  // Remove the ticket from the multiset
        }
    }
    
    // Output the results
    for (int price : result) {
        cout << price << endl;
    }
    
    return 0;
}
