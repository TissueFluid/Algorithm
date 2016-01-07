// Graph Valid Tree

#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> father;
public:
    UnionFind(int n) {
        father.resize(n);
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }
    }

    int Find(int m) {
        return father[m];
    }

    bool IsConnected(int m, int n) {
        return father[m] == father[n];
    }

    bool Union(int m, int n) {
        int father_m = father[m];
        int father_n = father[n];

        if (father_m > father_n) {
            swap(father_m, father_n);
            swap(m, n);
        }

        if (father_m != father_n) {
            for (int i = 0; i < father.size(); ++i) {
                if (father[i] == father_n) {
                    father[i] = father_m;
                }
            }
            return true;
        } else {
            return false;
        }
    }
};

class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n <= 0) {
            return  false;
        }

        if (edges.size() < n - 1) {
            return false;
        }

        UnionFind uf(n);

        for (const auto &edge : edges) {
            if (uf.Union(edge[0], edge[1]) == false) {
                return false;
            }
        }

        return true;
    }
};
