// Route Between Two Nodes in Graph

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode *> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        queue<DirectedGraphNode *> q;
        unordered_map<DirectedGraphNode *, bool> visited;

        for (const auto &item : graph) {
            visited[item] = false;
        }

        q.push(s);

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            if (front->label == t->label) {
                return true;
            }
            visited[front] = true;

            for (const auto &item : front->neighbors) {
                if (!visited[item]) {
                    q.push(item);
                }
            }
        }

        return false;
    }
};
