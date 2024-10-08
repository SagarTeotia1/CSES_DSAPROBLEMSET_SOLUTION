#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int edit_distance(const string &s1, const string &s2) {
    int n = s1.size();
    int m = s2.size();

    // Create a DP table with dimensions (n+1) x (m+1)
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // Base cases: transforming empty string to non-empty strings
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i; // Cost of deleting characters from s1 to match empty s2
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j; // Cost of inserting characters into empty s1 to match s2
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1]; // Characters match, no operation needed
            } else {
                dp[i][j] = min({dp[i-1][j] + 1,    // Deletion
                                dp[i][j-1] + 1,    // Insertion
                                dp[i-1][j-1] + 1}); // Replacement
            }
        }
    }

    // The final answer is the edit distance between the full strings
    return dp[n][m];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout << edit_distance(s1, s2) << endl;

    return 0;
}
