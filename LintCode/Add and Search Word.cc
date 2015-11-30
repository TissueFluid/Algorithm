// Add and Search Word

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct Trie {
    bool isLast;
    unordered_map<char, Trie*> m;
    Trie(bool isLast = false) {
        this->isLast = isLast;
    }
};

class WordDictionary {
private:
    Trie *root;

    bool search(const string &word, int start, Trie * root) {
        const int len = word.length();

        for ( ; start < len; ++start) {
            if (word[start] != '.') {
                if (root->m.find(word[start]) == root->m.end()) {
                    return false;
                } else {
                    root = root->m[word[start]];
                }
            } else {
                for (auto &item : root->m) {
                    if (this->search(word, start + 1, item.second) == true) {
                        return true;
                    }
                }
                return false;
            }
        }

        if (root->isLast) {
            return true;
        } else {
            return false;
        }
    }
public:
    WordDictionary() {
        this->root = new Trie();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        auto p = this->root;

        for (char ch : word) {
            if (p->m.find(ch) == p->m.end()) {
                p->m[ch] = new Trie();
            }
            p = p->m[ch];
        }

        p->isLast = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        this->search(word, 0, this->root);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
