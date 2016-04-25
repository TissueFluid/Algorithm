// Reverse Linked List II

#include <cstdio>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n || head == NULL) {
            return head;
        }

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        auto p = dummy;

        for (int i = 1; i <= m - 1; ++i) {
            p = p->next;
        }

        auto beforeFirst = p;
        auto first = p->next;
        p = first;

        for (int i = m; i <= n; ++i) {
            auto next = p->next;
            p->next = beforeFirst->next;
            beforeFirst->next = p;
            p = next;
        }

        first->next = p;

        auto ret = dummy->next;
        delete dummy;

        return ret;
    }
};


class Solution2 {
protected:
    ListNode *helper(ListNode *p, int n, ListNode * &after) {
        if (n == 1) {
            after = p->next;
            return p;
        }

        auto ret = helper(p->next, n - 1, after);

        p->next->next = p;

        return ret;
    }
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n || head == NULL) {
            return head;
        }

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        auto p = dummy;

        for (int i = 0; i < m - 1; ++i) {
            p = p->next;
        }

        auto first = p->next;
        ListNode *after;
        p->next = helper(first, n - m + 1, after);

        first->next = after;

        auto ret = dummy->next;
        delete dummy;

        return ret;
    }
};
