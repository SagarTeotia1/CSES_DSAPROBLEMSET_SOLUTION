#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class UnionFind {
private:
    vector<int> parent, size;
    int components, maxSize;

public:
    UnionFind(int n) : parent(n + 1), size(n + 1, 1), components(n), maxSize(1) {
        iota(parent.begin(), parent.end(), 0);  // Initialize parent array
    }

    int find(int a) {
        if (a == parent[a])
            return a;
        return parent[a] = find(parent[a]);  // Path compression
    }

    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA != rootB) {
            if (size[rootA] < size[rootB]) {
                swap(rootA, rootB);
            }
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
            maxSize = max(maxSize, size[rootA]);
            components--;
        }
    }

    int getComponents() const {
        return components;
    }

    int getMaxSize() const {
        return maxSize;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    UnionFind uf(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        uf.unite(a, b);
        cout << uf.getComponents() << " " << uf.getMaxSize() << endl;
    }

    return 0;
}
