// Implement Trie

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        ch = 0;
        isEnd = false;
    }

    TrieNode(char ch, bool isEnd) {
        this->ch = ch;
        this->isEnd = isEnd;
    }

    char ch;
    bool isEnd;
    unordered_map<char, TrieNode *> m;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        const int len = word.length();
        auto p = root;

        for (int i = 0; i < len; ++i) {
            if (p->m.find(word[i]) == p->m.end()) {
                p->m[word[i]] = new TrieNode(word[i], i == len - 1);
            } else {
                if (i == len - 1) {
                    p->m[word[i]]->isEnd = true;
                }
            }
            p = p->m[word[i]];
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        const int len = word.length();
        auto p = root;

        for (int i = 0; i < len; ++i) {
            if (p->m.find(word[i]) == p->m.end()) {
                return false;
            }
            p = p->m[word[i]];
        }

        return p->isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        const int len = prefix.length();
        auto p = root;

        for (int i = 0; i < len; ++i) {
            if (p->m.find(prefix[i]) == p->m.end()) {
                return false;
            }
            p = p->m[prefix[i]];
        }

        return true;
    }

private:
    TrieNode* root;
};
