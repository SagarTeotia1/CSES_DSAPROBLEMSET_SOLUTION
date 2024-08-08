#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to maximize the reward
long long maximizeReward(vector<pair<int, int>>& tasks) {
    // Sort tasks based on duration
    sort(tasks.begin(), tasks.end());

    long long total_reward = 0;
    long long current_time = 0;

    for (const auto& task : tasks) {
        int duration = task.first;
        int deadline = task.second;

        current_time += duration;
        total_reward += (deadline - current_time);
    }

    return total_reward;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> tasks(n);

    for (int i = 0; i < n; ++i) {
        int a, d;
        cin >> a >> d;
        tasks[i] = {a, d};
    }

    cout << maximizeReward(tasks) << endl;
    return 0;
}
