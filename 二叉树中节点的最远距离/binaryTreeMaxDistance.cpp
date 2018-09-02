//
// Created by mi on 3/5/18.
//
#include <iostream>


using namespace std;

typedef struct TreeNode{
public:
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}TNode;

class Solution{
public:
    int height(TNode *root){
        if (root == NULL) return  0;
        return max(height(root->left),height(root->right))+1;
    }

    int findMaxDistance(TNode *root){
        int leftMaxDistance;
        int righttMaxDistance;
        int leftHight=0;
        int rightHight=0;

        if (root ==NULL) return 0;

        leftMaxDistance=findMaxDistance(root->left);
        righttMaxDistance=findMaxDistance(root->right);

        if(root->left){
            leftHight=height(root->left);
        }

        if(root->right){
            rightHight=height(root->right);
        }
        return max(leftHight+rightHight+1,max(leftMaxDistance,righttMaxDistance));
    }
};
/*


int main(){
//
    TNode *node1;
    TNode *node2;
    TNode *node3;
    TNode *node4;
    TNode *node5;

//    node1->data=1;
//    cout<<node1->data;
//    node2->data=2;
//    node3->data=3;
//    node4->data=4;
//    node5->data=5;
//
//    node1->left=node2;
//    node1->right=node3;
//
//    node2->left=node4;
//    node2->right=node5;

    cout<<"**"<<endl;
//    Solution *solution;
//    int maxDistance=solution->findMaxDistance(node1);
//    cout<<"max_distance:\t"<<maxDistance<<endl;


}*/
