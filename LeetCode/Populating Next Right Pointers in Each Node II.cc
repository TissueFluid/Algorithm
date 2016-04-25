// Populating Next Right Pointers in Each Node II

#include <iostream>
using namespace std;

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
protected:
  TreeLinkNode *findNext(TreeLinkNode *p) {
    while (p) {
      if (p->left) {
        return p->left;
      }
      if (p->right) {
        return p->right;
      }
      p = p->next;
    }

    return nullptr;
  }
public:
  void connect(TreeLinkNode *root) {
    if (!root) {
      return;
    }

    TreeLinkNode *p = root;
    TreeLinkNode *first = findNext(root);

    while (first) {
      if (p->left && p->right) {
        p->left->next = p->right;
        p->right->next = findNext(p->next);
      } else if (p->left) {
        p->left->next = findNext(p->next);
      } else if (p->right) {
        p->right->next = findNext(p->next);
      }

      if (p->next) {
        p = p->next;
      } else {
        p = first;
        first = findNext(first);
      }
    }
  }
};
