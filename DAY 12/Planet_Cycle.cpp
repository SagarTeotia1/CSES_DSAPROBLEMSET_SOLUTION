#include <iostream>
#include <vector>

using namespace std;

void dfs(int u, vector<int>& t, vector<int>& visited, vector<int>& result, vector<int>& stack) {
    visited[u] = 1;
    stack.push_back(u);

    int v = t[u];
    if (visited[v] == 0) {
        dfs(v, t, visited, result, stack);
    } else if (visited[v] == 1) {
        // Found a cycle
        int cycle_length = 1;
        for (int i = stack.size() - 1; stack[i] != v; --i) {
            cycle_length++;
        }
        for (int i = stack.size() - 1; i >= 0; --i) {
            result[stack[i]] = cycle_length;
            if (stack[i] == v) break;
        }
    }

    visited[u] = 2;
    stack.pop_back();
    
    if (result[u] == 0) {
        result[u] = result[v] + 1;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> t(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }

    vector<int> visited(n + 1, 0);
    vector<int> result(n + 1, 0);
    vector<int> stack;

    for (int i = 1; i <= n; ++i) {
        if (visited[i] == 0) {
            dfs(i, t, visited, result, stack);
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
