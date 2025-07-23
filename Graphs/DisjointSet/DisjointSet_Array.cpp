#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
    vector<int> parent;
public:
    UnionFind(int size) {
      
        parent.resize(size);
      
        // Initialize the parent array with each 
        // element as its own representative
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    // Find the representative (root) of the
    // set that includes element i
    int find(int i) {
      
        // If i itself is root or representative
        if (parent[i] == i) {
            return i;
        }
      
        // Else recursively find the representative 
        // of the parent
        return find(parent[i]);
    }

    // Unite (merge) the set that includes element 
    // i and the set that includes element j
    void unite(int i, int j) {
      
        // Representative of set containing i
        int irep = find(i);
      
        // Representative of set containing j
        int jrep = find(j);
       
        // Make the representative of i's set
        // be the representative of j's set
        parent[jrep] = irep;
        
        for(auto node : parent)
        {
            cout<<node<<" ";
        }
        cout<<endl;
    }
};

int main() {
    int size = 5;
    UnionFind uf(size);
    bool inSameSet1 = (uf.find(0) == uf.find(1));
    cout << "Are 0 and 1 in the same set? " 
         << (inSameSet1 ? "Yes" : "No") << endl;
    bool inSameSet2 = (uf.find(1) == uf.find(2));
    cout << "Are 1 and 2 in the same set? " 
         << (inSameSet2 ? "Yes" : "No") << endl;
    uf.unite(1, 2);
    uf.unite(3, 4);
    bool inSameSet3 = (uf.find(1) == uf.find(2));
    cout << "Are 1 and 2 in the same set after union? " 
         << (inSameSet3 ? "Yes" : "No") << endl;
    
    return 0;
}
