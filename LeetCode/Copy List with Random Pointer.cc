// Copy List with Random Pointer

// old[0] -> new[0] -> old[1] -> new[1] ...
// 奇技淫巧

#include <iostream>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    for (auto p = head; p != nullptr; p = p->next->next) {
      auto newNode = new RandomListNode(p->label);
      newNode->next = p->next;
      newNode->random = p->random;
      p->next = newNode;
    }

    for (auto p = head; p != nullptr; p = p->next->next) {
      if (p->next->random) {
        p->next->random = p->next->random->next;
      }
    }

    auto oldList = new RandomListNode(0);
    auto newList = new RandomListNode(0);
    auto oldLast = oldList;
    auto newLast = newList;
    for (auto p = head; p != nullptr; p = p->next->next) {
      oldLast->next = p;
      newLast->next = p->next;
      oldLast = oldLast->next;
      newLast = newLast->next;
    }
    oldLast->next = newLast->next = nullptr;

    auto ret = newList->next;
    delete oldList;
    delete newList;

    return ret;
  }
};
