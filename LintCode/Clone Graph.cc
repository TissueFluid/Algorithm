// Clone Graph

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (node == NULL) {
        return NULL;
    }

    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> m;
    queue<UndirectedGraphNode *> q;

    auto head = new UndirectedGraphNode(node->label);
    m[node] = head;
    q.push(node);

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        auto size_neighbor = front->neighbors.size();

        for (size_t i = 0; i < size_neighbor; ++i) {
            auto neighbor = front->neighbors[i];

            if (m.find(neighbor) == m.end()) {
                m[neighbor] = new UndirectedGraphNode(neighbor->label);
                q.push(neighbor);
            }

            m[front]->neighbors.push_back(m[neighbor]);
        }
    }

    return head;
}
