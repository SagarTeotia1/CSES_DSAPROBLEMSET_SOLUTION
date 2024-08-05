#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> events;  // {time, type}, where type is +1 for arrival and -1 for departure

    for (int i = 0; i < n; ++i) {
        int arrival, departure;
        cin >> arrival >> departure;
        events.emplace_back(arrival, 1);   // Arrival event
        events.emplace_back(departure, -1); // Departure event
    }

    // Sort events. First by time, then by type (departures (-1) before arrivals (+1))
    sort(events.begin(), events.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first)
            return a.first < b.first;
        return a.second < b.second;  // Departures (-1) before arrivals (+1)
    });

    int current_customers = 0;
    int max_customers = 0;

    // Process all events
    for (const auto& event : events) {
        current_customers += event.second; // Update the number of current customers
        max_customers = max(max_customers, current_customers); // Track the maximum number of customers
    }

    cout << max_customers << endl;

    return 0;
}
