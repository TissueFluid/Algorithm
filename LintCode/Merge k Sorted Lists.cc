// Merge k Sorted Lists - priority queue

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Compare {
public:
    bool operator()(ListNode *a, ListNode *b) {
        return a->val < b->val;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<ListNode *, vector<ListNode *>, Compare> q;

    for (const auto &item : lists) {
        for (auto p = item; p != NULL; p = p->next) {
            q.push(p);
        }
    }

    auto dummy = new ListNode(0);

    while (!q.empty()) {
        auto top = q.top();
        q.pop();

        top->next = dummy->next;
        dummy->next = top;
    }

    ListNode *ret = dummy->next;
    delete dummy;

    return ret;
}

int main() {
    return 0;
}
