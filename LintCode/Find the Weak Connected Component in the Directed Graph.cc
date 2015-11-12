// Find the Weak Connected Component in the Directed Graph

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};

class DisjointSets {
private:
    unordered_map<int, int> father;
public:
    int Find(int a) {
        if (father.find(a) == father.end() || father[a] == a) {
            return a;
        } else {
            return Find(father[a]);
        }
    }

    void Union(int a, int b) {
        int fa = Find(a);
        int fb = Find(b);

        father[fa] = father[fb] = min(fa, fb);
    }
};

class Solution {
public:
    /**
     * @param nodes a array of directed graph node
     * @return a connected set of a directed graph
     */
    vector<vector<int>> connectedSet2(vector<DirectedGraphNode*>& nodes) {
        vector<vector<int> > result;

        if (nodes.empty()) {
            return result;
        }

        sort(nodes.begin(), nodes.end(),
             [](const DirectedGraphNode *a, const DirectedGraphNode *b) {
                 return a->label < b->label;
             });

        DisjointSets d;

        for (const auto &node : nodes) {
            d.Union(node->label, node->label);

            for (const auto &neighbor : node->neighbors) {
                d.Union(node->label, neighbor->label);
            }
        }

        unordered_map<int, vector<int> > group;

        for (const auto &node : nodes) {
            group[d.Find(node->label)].push_back(node->label);
        }

        for (auto &item : group) {
            sort(item.second.begin(), item.second.end());
            result.push_back(item.second);
        }

        return result;
    }
};
