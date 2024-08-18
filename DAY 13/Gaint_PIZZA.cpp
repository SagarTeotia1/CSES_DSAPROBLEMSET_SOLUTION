#include <bits/stdc++.h>
using namespace std;

const int MAXM = 2 * 100000 + 5;
vector<int> adj[MAXM], adj_rev[MAXM];
int component[MAXM];
bool assignment[MAXM];
stack<int> order;
bool visited[MAXM];

void add_implication(int u, int v) {
    adj[u].push_back(v);
    adj_rev[v].push_back(u);
}

void dfs1(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs1(v);
    }
    order.push(u);
}

void dfs2(int u, int comp) {
    component[u] = comp;
    for (int v : adj_rev[u]) {
        if (component[v] == -1) dfs2(v, comp);
    }
}

bool solve_2sat(int n) {
    memset(visited, 0, sizeof(visited));
    memset(component, -1, sizeof(component));
    
    // First pass to order the nodes
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) dfs1(i);
    }

    // Second pass to assign components
    int comp = 0;
    while (!order.empty()) {
        int u = order.top(); order.pop();
        if (component[u] == -1) dfs2(u, comp++);
    }

    // Check for conflicts in the same SCC
    for (int i = 0; i < n; i += 2) {
        if (component[i] == component[i^1]) return false;
        assignment[i / 2] = component[i] > component[i^1];
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Each topping `i` is represented by index `2*i` (included) and `2*i+1` (not included)
    for (int i = 0; i < n; ++i) {
        char sign1, sign2;
        int x1, x2;
        cin >> sign1 >> x1 >> sign2 >> x2;

        --x1; --x2;
        int u1 = 2 * x1 + (sign1 == '-' ? 1 : 0);
        int u2 = 2 * x2 + (sign2 == '-' ? 1 : 0);

        // Add implications for the 2-SAT problem
        add_implication(u1^1, u2); // ¬u1 -> u2
        add_implication(u2^1, u1); // ¬u2 -> u1
    }

    if (solve_2sat(2 * m)) {
        for (int i = 0; i < m; ++i) {
            cout << (assignment[i] ? '+' : '-');
        }
        cout << '\n';
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
