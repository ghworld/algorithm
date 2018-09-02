//
// Created by mi on 3/5/18.
//

#include <iostream>

using namespace std;



struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):data(x),left(NULL),right(NULL) {}
};


class Solution{
    // 搞不懂指向指针的指针是什么意思
    void ConvertNode(TreeNode *pNode, TreeNode **pLastNodeInList){

        TreeNode *pCurrent =pNode;
        if (pCurrent == NULL ) return;
        cout<< "pCurrent data:\t"<<pCurrent->data<<endl;
        if (pCurrent->left !=NULL) ConvertNode(pCurrent->left, pLastNodeInList);

        pCurrent->left=*pLastNodeInList;
        if((*pLastNodeInList) !=NULL ){
            (*pLastNodeInList)->right = pCurrent;
        }
        *pLastNodeInList=pCurrent;

        if (pCurrent->right !=NULL) ConvertNode(pCurrent->right, pLastNodeInList);

    }

public:
    TreeNode* Convert(TreeNode *pRootofTree){

        TreeNode *pLastNodeInList=NULL;
        ConvertNode(pRootofTree, &pLastNodeInList);
        TreeNode *head=pLastNodeInList;
        while (head !=NULL && head->left !=NULL){
            head=head->left;
        }
        return head;
    }

};

//
//int main(){
//    TreeNode *node1=new TreeNode(1);
//    TreeNode *node2=new TreeNode(2);
//    TreeNode *node3=new TreeNode(3);
//    TreeNode *node4=new TreeNode(4);
//    TreeNode *node5=new TreeNode(5);
//    TreeNode *node6=new TreeNode(6);
//
//    node4->left= node2;
//    node4 -> right =node6;
//    node2->left = node1;
//    node3 -> right =node3;
//    node6 -> left =node5;
//
//    Solution *solution=new Solution();
//    TreeNode *pHead= solution->Convert(node4);
//
//    while(pHead!=NULL && pHead->right!=NULL){
//        cout<< pHead->data<<endl;
//        pHead=pHead->right;
//    }
//
//cout << "**" <<endl;
//}
