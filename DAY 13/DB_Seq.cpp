#include <bits/stdc++.h>
using namespace std;

// Hierholzer's Algorithm for finding Eulerian path
void dfs(int u, vector<vector<int>>& adj, vector<int>& path) {
    while (!adj[u].empty()) {
        int v = adj[u].back();
        adj[u].pop_back();
        dfs(v, adj, path);
    }
    path.push_back(u);
}

string deBruijnSequence(int n) {
    if (n == 1) return "01";

    int k = 2; // Binary alphabet
    int num_vertices = 1 << (n - 1); // 2^(n-1)

    vector<vector<int>> adj(num_vertices);
    for (int i = 0; i < num_vertices; ++i) {
        adj[i].push_back((i << 1) & (num_vertices - 1));       // append '0'
        adj[i].push_back(((i << 1) & (num_vertices - 1)) | 1); // append '1'
    }

    vector<int> path;
    dfs(0, adj, path);
    reverse(path.begin(), path.end());

    string result;
    for (int i = 0; i < path.size(); ++i) {
        result += (path[i] & 1) + '0';
    }
    for (int i = 1; i < n; ++i) {
        result += (path[i] >> (n - 2)) + '0';
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    string sequence = deBruijnSequence(n);
    cout << sequence << endl;

    return 0;
}
