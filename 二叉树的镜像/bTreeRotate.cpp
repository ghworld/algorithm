//
// Created by mi on 2/27/18.
//


#include <iostream>


using namespace std;


struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};


class Solution {
public:
//普通的递归版本
    void rotate(TreeNode *root) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
            return;
        swap(root->left, root->right);
        rotate(root->left);
        rotate(root->right);
    }

    /*void swap(TreeNode *left, TreeNode *right) {
        TreeNode *tmp;
        *tmp = *left;
        *left = *right;
        *right = *tmp;
    }

    void swap_dizhi(int *x, int *y) {
        int *tmp;
        tmp = x;
        x = y;
        y = tmp;
    }

    void swap_yiyong(int &x, int &y) {
        int tmp;
        tmp = x;
        x = y;
        y = tmp;
    }*/

};




/*int main(){
    cout<<"this is a main!"<<endl;

    TreeNode *node1=new TreeNode(1);
    TreeNode *node2=new TreeNode(2);
    TreeNode *node3=new TreeNode(3);
    TreeNode *node4=new TreeNode(4);
    TreeNode *node5=new TreeNode(5);

    node1->left=node2;
    node1->right=node3;
    node2->left=node4;
    node2->right=node5;

    Solution solution;
//    cout<<node1->left->value<<endl;
//    cout<<node1->right->value<<endl;

    solution.swap(node1,node2);
    cout<<node1->value<<endl;
    cout<<node2->value<<endl;
    int a=1;
    int b =2;
    solution.swap_yiyong(a,b);
    cout<<" yinyong "<<endl;
    cout<<a<<" " << b<<endl;

    int *x=&a;
    int *y=&b;
    solution.swap_dizhi(x,y);
    cout<<" dizhi "<<endl;
    cout<<*x<<" " <<*y<<endl;

}*/
