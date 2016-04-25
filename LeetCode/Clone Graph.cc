// Clone Graph

#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (node == nullptr) {
      return nullptr;
    }

    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> m;
    queue<UndirectedGraphNode *> q({node});

    auto root = new UndirectedGraphNode(node->label);
    m[node] = root;

    while (!q.empty()) {
      const int qsize = q.size();

      for (int i = 0; i < qsize; ++i) {
        auto front = q.front();
        q.pop();

        for (const auto &neighbor : front->neighbors) {
          if (m.find(neighbor) == m.end()) {
            m[neighbor] = new UndirectedGraphNode(neighbor->label);
            q.push(neighbor);
          }
          m[front]->neighbors.push_back(m[neighbor]);
        }
      }
    }

    return root;
  }
};
