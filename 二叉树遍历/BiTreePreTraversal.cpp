//
// Created by mi on 8/8/18.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        this->val = x;
        this->left = NULL;
        this->right = NULL;
    }
};


class Solution {
public:
    vector<int> preTraverse(TreeNode *root) {
//       这个是深度优先的遍历
        vector<int> result;
        if (root == NULL) return result;
        stack<TreeNode *> s;
        s.push(root);
        while (s.empty() != true) {
            TreeNode *node = s.top();
            s.pop();
            result.push_back(node->val);
            if (node->right != NULL) {
                s.push(node->right);
            }
            if (node->left != NULL) {
                s.push(node->left);
            }
        }
        return result;
    }

};

class Solution2 {
//    递归版本
public:
    void preTraverse(TreeNode *root, vector<int> &result) {

        if (root == NULL) {
            return;
        }
//        cout << root->val << endl;
        result.push_back(root->val);
        preTraverse(root->left, result);
        preTraverse(root->right, result);
        return;
    };
};
/*



int main() {
//    写个UT
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node7 = new TreeNode(7);

    node1->left = node2;
    node1->right = node3;

    node2->left = node4;
    node2->right = node5;

    node3->left = node6;
    node3->right = node7;

//    迭代版本
    Solution2 *sRe = new Solution2();
    vector<int> result = {};
    sRe->preTraverse(node1, result);
    for (int i = 0; i < result.size(); i++) {
        cout << result.at(i) << endl;
    }
    cout << "#####################" << endl;

//   递归版本
    Solution *sIt = new Solution();
    vector<int> ret = sIt->preTraverse(node1);
    for (int i = 0; i < ret.size(); i++) {
        cout << result.at(i) << endl;
    }

}*/
