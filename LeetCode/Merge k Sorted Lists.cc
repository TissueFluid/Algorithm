// Merge k Sorted Lists

#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// heap
// time : O( n * log(k) )
// space: O( k )
class Solution1 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode *a, ListNode *b) {
            return a->val > b->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> heap(cmp);

        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;

        for (const auto &list : lists) {
            if (list) {
                heap.push(list);
            }
        }

        while (!heap.empty()) {
            tail->next = heap.top();
            heap.pop();
            tail = tail->next;
            if (tail->next) {
                heap.push(tail->next);
            }
        }

        auto ret = dummy->next;
        delete dummy;

        return ret;
    }
};

// dichotomy
// time  : O( n * log(k) )
// space : O(1)

class Solution2 {
private:
    ListNode *merge2Lists(ListNode *a, ListNode *b) {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;

        while (a && b) {
            if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        if (a) {
            tail->next = a;
        }

        if (b) {
            tail->next = b;
        }

        auto ret = dummy->next;
        delete dummy;

        return ret;
    }
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        const auto size = lists.size();

        if (size == 0) {
            return NULL;
        }

        int end = size - 1;

        while (end > 0) {
            int begin = 0;
            while (begin < end) {
                lists[begin] = merge2Lists(lists[begin], lists[end]);
                begin++;
                end--;
            }
        }

        return lists[0];
    }
};
