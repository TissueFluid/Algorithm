// Implement Trie (Prefix Tree)

#include <string>
#include <unordered_map>
#include <cstring>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        isEnd = false;
        memset(children, 0, sizeof(children));
    }

    bool isEnd;
    TrieNode *children[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        auto p = root;
        for (const auto &ch : word) {
            if (p->children[ch - 'a'] == NULL) {
                p->children[ch - 'a'] = new TrieNode();
            }
            p = p->children[ch - 'a'];
        }
        p->isEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        auto p = root;
        for (const auto &ch : word) {
            if (p->children[ch - 'a'] != NULL) {
                p = p->children[ch - 'a'];
            } else {
                return false;
            }
        }
        return p->isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        auto p = root;
        for (const auto &ch : prefix) {
            if (p->children[ch - 'a'] != NULL) {
                p = p->children[ch - 'a'];
            } else {
                return false;
            }
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
