// Linked List Cycle II

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next) {
      return nullptr;
    }

    auto slow = head;
    auto fast = head->next;

    while (fast && fast->next) {
      if (fast == slow) {
        auto slow2 = head;
        slow = slow->next;
        while (slow2 != slow) {
          slow2 = slow2->next;
          slow = slow->next;
        }
        return slow;
      }
      slow = slow->next;
      fast = fast->next->next;
    }

    return nullptr;
  }
};
