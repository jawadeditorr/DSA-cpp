#include <iostream>
#include <vector>
using namespace std;

class DSU {
    vector<int> parent, size;

public:

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find with Path Compression
    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    // Union by Size
    void unionSets(int a, int b) {

        a = find(a);
        b = find(b);

        if (a != b) {

            // smaller tree -> bigger tree
            if (size[a] < size[b]) {
                swap(a, b);
            }

            parent[b] = a;
            size[a] += size[b];
        }
    }
};

int main() {

    DSU dsu(7);

    dsu.unionSets(1, 2);
    dsu.unionSets(2, 3);

    dsu.unionSets(4, 5);

    // Check if same set
    if (dsu.find(1) == dsu.find(3)) {
        cout << "1 and 3 are in same set\n";
    }

    if (dsu.find(1) != dsu.find(5)) {
        cout << "1 and 5 are NOT in same set\n";
    }

    dsu.unionSets(3, 5);

    if (dsu.find(1) == dsu.find(5)) {
        cout << "Now 1 and 5 are connected\n";
    }

    return 0;
}