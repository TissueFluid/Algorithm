// Find the Connected Component in the Undirected Graph

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

class Solution {
private:
    void BFS(vector<vector<int> > &result,
             unordered_map<UndirectedGraphNode *, bool> &visited,
             UndirectedGraphNode *node) {
        vector<int> row;
        queue<UndirectedGraphNode *> q;

        q.push(node);

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            visited[front] = true;
            row.push_back(front->label);

            for (auto neighbor : front->neighbors) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        sort(row.begin(), row.end());
        result.push_back(row);
    }
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
        vector<vector<int> > result;

        const int size = nodes.size();

        if (size == 0) {
            return result;
        }

        unordered_map<UndirectedGraphNode *, bool> visited;

        for (auto node : nodes) {
            visited[node] = false;
        }

        for (auto node : nodes) {
            if (!visited[node]) {
                BFS(result, visited, node);
            }
        }

        return result;
    }
};
