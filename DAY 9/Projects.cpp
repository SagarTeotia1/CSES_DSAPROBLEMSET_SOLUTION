#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Project {
    int start, end, reward;
};

bool compareEnd(Project a, Project b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;
    
    vector<Project> projects(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
    }
    
    // Sort projects by their end time
    sort(projects.begin(), projects.end(), compareEnd);
    
    vector<long long> dp(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        // Option 1: Do not take the current project
        dp[i] = dp[i-1];
        
        // Option 2: Take the current project, find the last non-overlapping project
        int l = 0, r = i - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (projects[mid-1].end < projects[i-1].start) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        
        // Include the current project's reward
        dp[i] = max(dp[i], projects[i-1].reward + dp[l]);
    }
    
    cout << dp[n] << endl;
    
    return 0;
}
