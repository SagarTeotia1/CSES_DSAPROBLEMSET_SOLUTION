#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// Function to find the largest ticket price <= max_price using binary search
int find_ticket(vector<int>& tickets, int max_price) {
    int low = 0, high = tickets.size() - 1;
    int result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (tickets[mid] <= max_price) {
            result = tickets[mid];
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> tickets(n);
    vector<int> customers(m);
    
    for (int i = 0; i < n; ++i) {
        cin >> tickets[i];
    }
    
    for (int i = 0; i < m; ++i) {
        cin >> customers[i];
    }
    
    // Sort the tickets
    sort(tickets.begin(), tickets.end());
    
    set<int> available_tickets(tickets.begin(), tickets.end());
    
    for (int i = 0; i < m; ++i) {
        int max_price = customers[i];
        int ticket = find_ticket(tickets, max_price);
        
        if (ticket != -1) {
            cout << ticket << endl;
            available_tickets.erase(ticket);
            if (!available_tickets.empty()) {
                // Rebuild the tickets vector with remaining tickets
                tickets.clear();
                tickets.insert(tickets.end(), available_tickets.begin(), available_tickets.end());
                sort(tickets.begin(), tickets.end());
            }
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}
