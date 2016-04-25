// Populating Next Right Pointers in Each Node

#include <iostream>
using namespace std;

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
  void connect(TreeLinkNode *root) {
    if (!root) {
      return;
    }

    TreeLinkNode *p = root;
    TreeLinkNode *first = root->left;

    while (first) {
      p->left->next = p->right;
      if (p->next) {
        p->right->next = p->next->left;
        p = p->next;
      } else {
        p = first;
        first = first->left;
      }
    }
  }
};
