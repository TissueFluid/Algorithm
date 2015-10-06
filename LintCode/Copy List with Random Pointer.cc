// Copy List with Random Pointer

#include <iostream>
#include <unordered_map>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
    if (head == NULL) {
        return NULL;
    }

    unordered_map<RandomListNode *, RandomListNode *> m;
    RandomListNode *new_head = new RandomListNode(head->label);
    RandomListNode *last = new_head;
    m[head] = new_head;

    RandomListNode *p, *q;

    for (p = head->next; p; p = p->next) {
        RandomListNode *tmp = new RandomListNode(p->label);
        last->next = tmp;
        last = last->next;
        m[p] = tmp;
    }

    for (p = head, q = new_head; p && q; p = p->next, q = q->next) {
        if (p->random) {
            q->random = m[p->random];
        }
    }

    return new_head;
}
