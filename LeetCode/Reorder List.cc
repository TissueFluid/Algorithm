// Reorder List

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
protected:
  ListNode *findMiddle(ListNode *head) {
    if (!head) {
      return nullptr;
    }

    auto slow = head;
    auto fast = slow->next;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }

  ListNode *reverse(ListNode *head) {
    auto dummy = new ListNode(0);
    ListNode *next;

    while (head) {
      next = head->next;
      head->next = dummy->next;
      dummy->next = head;
      head = next;
    }

    auto ret = dummy->next;
    delete dummy;
    return ret;
  }
public:
  void reorderList(ListNode* head) {
    if (!head) {
      return;
    }
    auto middle = findMiddle(head);
    auto reversed = reverse(middle->next);
    middle->next = nullptr;

    for (auto p = head; reversed != nullptr; p = p->next->next) {
      auto toBeInserted = reversed;
      reversed = reversed->next;

      toBeInserted->next = p->next;
      p->next = toBeInserted;
    }
  }
};
