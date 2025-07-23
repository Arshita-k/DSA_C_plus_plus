#include <iostream>
#include <vector>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0); //initially all the nodes has rank 0
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unionByRank(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};


int main() {
    int size = 5;
    DSU uf(size);
    bool inSameSet1 = (uf.find(0) == uf.find(1));
    cout << "Are 0 and 1 in the same set? " 
         << (inSameSet1 ? "Yes" : "No") << endl;
    bool inSameSet2 = (uf.find(1) == uf.find(2));
    cout << "Are 1 and 2 in the same set? " 
         << (inSameSet2 ? "Yes" : "No") << endl;
    uf.unionByRank(0, 1);
    uf.unionByRank(1, 2);
    bool inSameSet3 = (uf.find(1) == uf.find(2));
    cout << "Are 1 and 2 in the same set after union? " 
         << (inSameSet3 ? "Yes" : "No") << endl;
    
    return 0;
}
