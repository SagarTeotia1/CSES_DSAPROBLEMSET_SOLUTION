#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++) {
        cin >> movies[i].first >> movies[i].second;
    }

    // Sort movies by their end times
    sort(movies.begin(), movies.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    // Priority queue to store the end times of the movies being watched
    priority_queue<int, vector<int>, greater<int>> pq;

    int count = 0;

    for (const auto& movie : movies) {
        int start = movie.first;
        int end = movie.second;

        if (pq.size() < k) {
            // If there are fewer than k movies being watched, just watch this one
            pq.push(end);
            count++;
        } else if (pq.top() <= start) {
            // If the earliest ending movie ends before the current movie starts, replace it
            pq.pop();
            pq.push(end);
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
