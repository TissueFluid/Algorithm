// Topological Sorting
//   DFS/BFS

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};

vector<DirectedGraphNode *> topSort(vector<DirectedGraphNode *> graph) {
    unordered_map<DirectedGraphNode *, int> m;
    auto size = graph.size();

    for (auto node : graph) {
        if (m.find(node) == m.end()) {
            m[node] = 0;
        }
        for (auto neighbor : node->neighbors) {
            if (m.find(neighbor) != m.end()) {
                m[neighbor]++;
            } else {
                m[neighbor] = 1;
            }
        }
    }

    vector<DirectedGraphNode *> result;
    queue<DirectedGraphNode *> q;

    while (result.size() != size) {
        for (auto &item : m) {
            if (item.second == 0) {
                q.push(item.first);
            }
        }

        while (!q.empty()) {
            auto front = q.front();

            result.push_back(front);
            m[front]--;
            for (auto neighbor : front->neighbors) {
                m[neighbor]--;
            }
            q.pop();
        }
    }

    return result;
}
