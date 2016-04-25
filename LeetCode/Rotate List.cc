// Rotate List

#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    int length(ListNode *head, ListNode *&last) {
        int count = 0;
        while (head) {
            count++;
            last = head;
            head = head->next;
        }
        return count;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) {
            return NULL;
        }

        ListNode *last;
        int len = length(head, last);
        k %= len;

        if (k == 0) {
            return head;
        }

        last->next = head;
        for (int i = 0; i < len - k; ++i) {
            head = head->next;
            last = last->next;
        }
        last->next = NULL;

        return head;
    }
};
