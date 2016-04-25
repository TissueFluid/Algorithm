struct TrieNode {
    bool isEnd;
    TrieNode *children[26];

    TrieNode() {
        isEnd = false;
        memset(children, 0, sizeof(children));
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void Insert(const string &word) {
        auto p = root;
        for (const auto &ch : word) {
            if (p->children[ch - 'a'] == NULL) {
                p->children[ch - 'a'] = new TrieNode();
            }
            p = p->children[ch - 'a'];
        }
        p->isEnd = true;
    }

    void Search(vector<vector<char> > &board, vector<string> &result) {
        const int height = board.size();
        const int width = board[0].size();

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                dfs(board, root, i, j, result);
            }
        }
    }

protected:
    TrieNode *root;

    void dfs(vector<vector<char> > &board, TrieNode *p, int x, int y,
             vector<string> &result) {
        static string tmp("");

        if (p->isEnd == true) {
            result.push_back(tmp);
            p->isEnd = false;
        }

        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) {
            return;
        }

        if (board[x][y] == '\0') {
            return;
        }

        auto nextp = p->children[board[x][y] - 'a'];
        if (nextp == NULL) {
            return;
        }

        tmp.push_back(board[x][y]);
        auto backup = board[x][y];
        board[x][y] = '\0';
        dfs(board, nextp, x + 1, y, result);
        dfs(board, nextp, x - 1, y, result);
        dfs(board, nextp, x, y + 1, result);
        dfs(board, nextp, x, y - 1, result);
        board[x][y] = backup;
        tmp.pop_back();
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.size() == 0 || board[0].size() == 0 || words.size() == 0) {
            return {};
        }

        Trie trie;

        for (const auto &word : words) {
            trie.Insert(word);
        }

        vector<string> result;

        trie.Search(board, result);

        return result;
    }
};
