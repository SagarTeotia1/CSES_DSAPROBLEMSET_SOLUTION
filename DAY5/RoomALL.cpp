#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Customer {
    long long arrival, departure;
    int index;
    
    bool operator<(const Customer& other) const {
        return arrival < other.arrival;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    vector<Customer> customers(n);
    for (long long i = 0; i < n; ++i) {
        cin >> customers[i].arrival >> customers[i].departure;
        customers[i].index = i;
    }

    // Sort customers by arrival day (and by departure day if arrival days are the same)
    sort(customers.begin(), customers.end());

    // Min-Heap to keep track of the end days of the rooms
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> roomHeap;
    vector<int> roomAssignment(n);
    int roomCount = 0;

    for (const auto& customer : customers) {
        // Check if we can reuse a room
        if (!roomHeap.empty() && roomHeap.top().first < customer.arrival) {
            auto [endDay, roomNumber] = roomHeap.top();
            roomHeap.pop();
            roomAssignment[customer.index] = roomNumber;
            roomHeap.push({customer.departure, roomNumber});
        } else {
            // Need a new room
            roomCount++;
            roomAssignment[customer.index] = roomCount;
            roomHeap.push({customer.departure, roomCount});
        }
    }

    // Print the result
    cout << roomCount << "\n";
    for (const auto& assignment : roomAssignment) {
        cout << assignment << " ";
    }
    cout << "\n";

    return 0;
}
