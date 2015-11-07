// Rehashing

#include <iostream>
#include <vector>
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

class Solution {
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        vector<ListNode *> result;

        const int old_cap = hashTable.size();

        if (old_cap == 0) {
            return result;
        }

        const int new_cap = old_cap * 2;

        result = vector<ListNode *>(new_cap, NULL);
        vector<ListNode *> last(new_cap, NULL);

        for (int i = 0; i < old_cap; ++i) {
            for (auto p = hashTable[i]; p != NULL; p = p->next) {
                int hash_code;
                if (p->val >= 0) {
                    hash_code = p->val % new_cap;
                } else {
                    hash_code = p->val % new_cap + new_cap;
                }

                if (result[hash_code] == NULL) {
                    result[hash_code] = new ListNode(p->val);
                    last[hash_code] = result[hash_code];
                } else {
                    last[hash_code]->next = new ListNode(p->val);
                    last[hash_code] = last[hash_code]->next;
                }
            }
        }

        return result;
    }
};
