// Word Search II - Trie

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

struct TreeNode {
    bool isEnd;
    string value;
    unordered_map<char, TreeNode *> children;

    TreeNode() {
        this->isEnd = false;
    }
};

class Trie {
protected:
    TreeNode *root;

    void dfs(vector<vector<char> > &board,
             int x, int y, TreeNode *root,
             unordered_set<string> &result) {
        static auto height = board.size();
        static auto width = board[0].size();

        if (x < 0 || y < 0 || x >= height || y >= width) {
            return;
        }

        if (board[x][y] == 0) {
            return;
        }

        auto found = root->children.find(board[x][y]);
        if (found == root->children.end()) {
            return;
        }

        if (found->second->isEnd == true) {
            result.insert(found->second->value);
        }

        auto origin = board[x][y];

        board[x][y] = 0;

        dfs(board, x, y + 1, found->second, result);
        dfs(board, x, y - 1, found->second, result);
        dfs(board, x + 1, y, found->second, result);
        dfs(board, x - 1, y, found->second, result);

        board[x][y] = origin;
    }

public:
    Trie() {
        this->root = new TreeNode();
    }

    ~Trie() {
        stack<TreeNode *> s;

        s.push(this->root);

        while (!s.empty()) {
            auto top = s.top();
            s.pop();

            for (const auto &key_and_value: top->children) {
                s.push(key_and_value.second);
            }

            delete top;
        }
    }

    void Insert(string str) {
        TreeNode *p = root;
        for (const auto ch : str) {
            if (p->children.find(ch) == p->children.end()) {
                p->children[ch] = new TreeNode();
            }
            p = p->children[ch];
        }
        p->isEnd = true;
        p->value = str;
    }

    void Search(vector<vector<char> > &board, vector<string> &result) {
        auto height = board.size();

        if (height == 0) {
            return;
        }

        auto width = board[0].size();

        unordered_set<string> s;

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                this->dfs(board, i, j, this->root, s);
            }
        }

        result.assign(s.begin(), s.end());
    }
};

vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) {
    Trie trie;

    for (const auto &word : words) {
        trie.Insert(word);
    }

    vector<string> result;

    trie.Search(board, result);

    return result;
}

int main() {
    vector<vector<char> > board = {
        {'d', 'o', 'a', 'f'},
        {'a', 'g', 'a', 'i'},
        {'d', 'c', 'a', 'n'}
    };

    vector<string> words = {"dog", "dad", "dgdg", "can", "again"};

    auto result = wordSearchII(board, words);

    for (const auto &item : result) {
        cout << item << endl;
    }

    return 0;
}
