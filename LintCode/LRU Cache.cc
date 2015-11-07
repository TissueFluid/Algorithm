// LRU Cache

#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int key;
    int value;
    Node *next;
    Node *prev;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache{
private:
    Node *first;
    Node *last;
    int size;
    int cap;

    Node *find(int key) {
        for (Node *p = this->first; p != NULL; p = p->next) {
            if (p->key == key) {
                return p;
            }
        }
        return NULL;
    }

    void moveToFirst(Node *found) {
        if (found != this->first) {
            found->prev->next = found->next;
            if (found != this->last) {
                found->next->prev = found->prev;
            } else {
                this->last = found->prev;
            }
            found->next = this->first;
            this->first->prev = found;
            this->first = found;
        }
    }
public:
    // @param capacity, an integer
    LRUCache(int capacity) {
        this->cap = capacity;
        this->size = 0;
        this->first = NULL;
        this->last = NULL;
    }

    // @return an integer
    int get(int key) {
        Node *found = this->find(key);

        if (found == NULL) {
            return -1;
        } else {
            this->moveToFirst(found);
            return found->value;
        }
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        Node *found = this->find(key);

        if (found == NULL) {
            Node *new_node = new Node(key, value);

            if (this->first) {
                new_node->next = this->first;
                this->first->prev = new_node;
                this->first = new_node;
            } else {
                this->first = this->last = new_node;
            }

            if (this->size < this->cap) {
                this->size++;
            } else {
                this->last = this->last->prev;
                delete this->last->next;
                this->last->next = NULL;
            }
        } else {
            found->value = value;
            this->moveToFirst(found);
        }
    }
};
