// LRU Cache

#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
  Node *prev;
  Node *next;
  int key;
  int value;
  Node() : Node(0, 0) {}
  Node(int _key, int _value) : key(_key), value(_value) {
    prev = next = nullptr;
  }
};

class LRUCache{
protected:
  int cap;
  int len;
  Node *begin;
  Node *end;
  unordered_map<int, Node*> m;

  Node *find(int key) {
    auto found = m.find(key);

    if (found == m.end()) {
      return nullptr;
    }

    return found->second;
  }

  void erase(Node *p) {
    p->next->prev = p->prev;
    p->prev->next = p->next;
  }

  void appendToFront(Node *p) {
    p->next = begin->next;
    p->prev = begin;
    p->next->prev = p;
    p->prev->next = p;
  }

  void moveToFront(Node *p) {
    erase(p);
    appendToFront(p);
  }

public:
  LRUCache(int capacity) {
    len = 0;
    cap = capacity;
    begin = new Node();
    end = new Node();
    begin->next = end;
    end->prev = begin;
  }

  int get(int key) {
    auto found = find(key);

    if (found == nullptr) {
      return -1;
    }
    moveToFront(found);

    return found->value;
  }

  void set(int key, int value) {
    auto found = find(key);

    if (found == nullptr) {
      auto newNode = new Node(key, value);
      if (len == cap) {
        m.erase(end->prev->key);
        erase(end->prev);
      } else {
        ++len;
      }
      appendToFront(newNode);
      m[key] = newNode;
    } else {
      found->value = value;
      moveToFront(found);
    }
  }
};
