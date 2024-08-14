#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> findCourseOrder(int n, const vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> adj(n + 1);
    vector<int> inDegree(n + 1, 0);

    // Build the graph
    for (auto& prereq : prerequisites) {
        int u = prereq.first, v = prereq.second;
        adj[u].push_back(v);
        inDegree[v]++;
    }

    // Kahn's algorithm for topological sorting
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        order.push_back(course);

        for (int neighbor : adj[course]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If the number of courses in the order is less than n, there is a cycle
    if (order.size() < n) {
        return {};
    }
    return order;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> prerequisites(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        prerequisites[i] = {a, b};
    }

    vector<int> courseOrder = findCourseOrder(n, prerequisites);

    if (courseOrder.empty()) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int course : courseOrder) {
            cout << course << " ";
        }
        cout << "\n";
    }

    return 0;
}
