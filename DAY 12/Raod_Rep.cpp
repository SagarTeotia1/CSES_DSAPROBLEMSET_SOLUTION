#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, cost;
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

class UnionFind {
private:
    vector<int> parent, size;

public:
    UnionFind(int n) : parent(n + 1), size(n + 1, 1) {
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int a) {
        if (a == parent[a])
            return a;
        return parent[a] = find(parent[a]);  // Path compression
    }

    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA != rootB) {
            if (size[rootA] < size[rootB]) swap(rootA, rootB);
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
            return true;
        }
        return false;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;
    }

    // Sort edges by cost
    sort(edges.begin(), edges.end());

    UnionFind uf(n);
    int totalCost = 0;
    int edgesUsed = 0;

    for (const auto& edge : edges) {
        if (uf.unite(edge.u, edge.v)) {
            totalCost += edge.cost;
            edgesUsed++;
            if (edgesUsed == n - 1) break;  // We only need n-1 edges for MST
        }
    }

    if (edgesUsed == n - 1) {
        cout << totalCost << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
