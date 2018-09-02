//
// Created by mi on 3/7/18.
//



#include <iostream>


// http://cuijiahua.com/blog/2017/12/basis_26.html
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        //用于记录双向链表尾结点
        TreeNode* pLastNodeInList = NULL;

        //开始转换结点
        ConvertNode(pRootOfTree, &pLastNodeInList);

        //pLastNodeInList指向双向链表的尾结点，我们需要重新返回头结点
        TreeNode* pHeadOfList = pLastNodeInList;
        while(pHeadOfList != NULL && pHeadOfList->left != NULL){
            pHeadOfList = pHeadOfList->left;
        }
        return pHeadOfList;
    }

    void ConvertNode(TreeNode* pNode, TreeNode** pLastNodeInList){
        //叶结点直接返回
        if(pNode == NULL){
            return;
        }

        TreeNode* pCurrent = pNode;
        cout<< "pCurrent data:\t"<<pCurrent->val<<endl;
        //递归左子树
        if(pCurrent->left != NULL)
            ConvertNode(pCurrent->left, pLastNodeInList);

        //左指针
        pCurrent->left = *pLastNodeInList;
        //右指针
        if(*pLastNodeInList != NULL){
            (*pLastNodeInList)->right = pCurrent;
        }
        //更新双向链表尾结点
        *pLastNodeInList = pCurrent;
        //递归右子树
        if(pCurrent->right != NULL){
            ConvertNode(pCurrent->right, pLastNodeInList);
        }
    }
};



/*
int main(){
    TreeNode *node1=new TreeNode(1);
    TreeNode *node2=new TreeNode(2);
    TreeNode *node3=new TreeNode(3);
    TreeNode *node4=new TreeNode(4);
    TreeNode *node5=new TreeNode(5);
    TreeNode *node6=new TreeNode(6);

    node4->left= node2;
    node4 -> right =node6;
    node2->left = node1;
    node3 -> right =node3;
    node6 -> left =node5;



    Solution *solution;
    TreeNode *pHead=solution->Convert(node4);

    while(pHead!=NULL && pHead->right!=NULL){
        cout<< pHead->val<<endl;
        pHead=pHead->right;
    }

    cout << "**" <<endl;
}
*/



