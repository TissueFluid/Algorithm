// Binary Tree Serialization

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string serialize(TreeNode *root) {
    if (root == NULL) {
        return string("#");
    }

    stack<TreeNode *> s;
    string result("");
    s.push(root);

    while (!s.empty()) {
        TreeNode *top = s.top();
        s.pop();

        if (top != NULL) {
            s.push(top->right);
            s.push(top->left);
            result += to_string(top->val) + ",";
        } else {
            result += "#,";
        }
    }

    return result.substr(0, result.length() - 1);
}

TreeNode *deserialize(string data) {
    stringstream ss(data);
    string tok;

    getline(ss, tok, ',');

    if (tok == "#") {
        return NULL;
    }

    TreeNode *root = new TreeNode(stoi(tok));
    TreeNode *p = root;
    stack<TreeNode *> s;
    s.push(p);
    bool right = false;

    while (getline(ss, tok, ',')) {
        if (tok == "#") {
            if (!s.empty()) {
                p = s.top();
                s.pop();
            }
            right = true;
        } else {
            if (right) {
                p->right = new TreeNode(stoi(tok));
                p = p->right;
            } else {
                p->left = new TreeNode(stoi(tok));
                p = p->left;
            }
            s.push(p);
            right = false;
        }
    }

    return root;
}

int main() {
    cout << serialize(deserialize(string("3,9,#,#,20,15,#,#,7,#,#"))) << endl;
    cout << serialize(deserialize(string("1,#,2,#,#"))) << endl;
    cout << serialize(deserialize(string("1,2,#,#,3,#,#"))) << endl;
}
