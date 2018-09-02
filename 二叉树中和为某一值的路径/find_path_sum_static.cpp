//
// Created by mi on 8/29/18.
//

#include <vector>
#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
    TreeNode(int x):val(x),left(NULL),right(NULL){

    }
};

#define debug cout

class Solution {
public:
    vector<vector<int> > m_res;

    vector<vector<int> > FindPath(TreeNode *root, int expectNumber) {
        if (root == NULL) {
            return m_res;
        }
        vector<int> path;
        FindPathRecursion(root, expectNumber);

        return m_res;
    }


    void FindPathRecursion(TreeNode *root, int expectNumber) {
        static int currentSum = 0;
        static vector<int> path;

        currentSum += root->val;
        path.push_back(root->val);
        debug << "currentSum = " << currentSum - root->val << ", now get " << root->val << ", currentSum = "
              << currentSum << endl;
        ///
        if (currentSum == expectNumber
            && ((root->left == NULL && root->right == NULL))) {
            debug << "find a path" << endl;
            for (int i = 0; i < path.size(); i++) {
                debug << path[i] << " ";
            }
            debug << endl;

            m_res.push_back(path);
        }

        if (root->left != NULL) {
            FindPathRecursion(root->left, expectNumber);
        }
        if (root->right != NULL) {
            FindPathRecursion(root->right, expectNumber);
        }

        debug << "currentSum = " << currentSum << ", now pop " << *(path.end() - 1) << ", currentSum = "
              << currentSum - root->val << endl;
        //  作为静态变量存储需要恢复现场
        currentSum -= root->val;
        path.pop_back();

    }

};