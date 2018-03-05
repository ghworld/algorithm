//
// Created by mi on 12/11/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>



using namespace std;

typedef struct NODE {
    struct NODE *pLeft;        // 左子树
    struct NODE *pRight;       // 右子树
    int nMaxLeft;       // 左子树中的最长距离
    int nMaxRight;      // 右子树中的最长距离
    char chValue;       // 该节点的值
} NODE,*BTree;

struct NODEM{
    NODEM *pLeft;        // 左子树
    NODEM *pRight;       // 右子树
    int nMaxLeft;       // 左子树中的最长距离
    int nMaxRight;      // 右子树中的最长距离
    char chValue;       // 该节点的值
};

int nMaxLen = 0;
void FindMaxLen(NODE* root);



// 寻找树中最长的两段距离
void FindMaxLen(NODE *pRoot) {
    // 遍历到叶子节点，返回
    if (pRoot == NULL) {
        return;
    }

    // 如果左子树为空，那么该节点的左边最长距离为0
    if (pRoot->pLeft == NULL) {
        pRoot->nMaxLeft = 0;
    }

    // 如果右子树为空，那么该节点的右边最长距离为0
    if (pRoot->pRight == NULL) {
        pRoot->nMaxRight = 0;
    }

    // 如果左子树不为空，递归寻找左子树最长距离
    if (pRoot->pLeft != NULL) {
        FindMaxLen(pRoot->pLeft);
    }

    // 如果右子树不为空，递归寻找右子树最长距离
    if (pRoot->pRight != NULL) {
        FindMaxLen(pRoot->pRight);
    }

    // 计算左子树最长节点距离
    if (pRoot->pLeft != NULL) {
        pRoot->nMaxLeft = ((pRoot->pLeft->nMaxLeft > pRoot->pLeft->nMaxRight) ? pRoot->pLeft->nMaxLeft
                                                                              : pRoot->pLeft->nMaxRight) + 1;
    }

    // 计算右子树最长节点距离
    if (pRoot->pRight != NULL) {
        pRoot->nMaxRight = ((pRoot->pRight->nMaxLeft > pRoot->pRight->nMaxRight) ? pRoot->pRight->nMaxLeft
                                                                                 : pRoot->pRight->nMaxRight) + 1;
    }

    // 更新最长距离
    if (pRoot->nMaxLeft + pRoot->nMaxRight > nMaxLen) {
        nMaxLen = pRoot->nMaxLeft + pRoot->nMaxRight;
    }
}


/*
int main(){
    printf("niaho,binaryTreeMaxLen");
    std::cout<<"\nniaho"<<endl;
    BTree  bTree;
    bTree->chValue='g';
    cout<<bTree->chValue<<endl;
    *//*struct NODEM node1;
    node1.chValue='g';
    std::cout<<node1.chValue;
    *//*

*//*
    BNode node1;
    node1.chValue='h';
    cout<<node1.chValue<<endl;

*//*




//BNode *node1;


*//*
    NODE *node2;
    node1.chValue = 'u';
    NODE *node3;
    node1.chValue = 'o';
    NODE *node4;
    node1.chValue = 'h';
    NODE *node5;
    node1.chValue = 'a';
    node1.pLeft=node2;
    node1.pRight=node3;
    node2->pLeft=node4;
    node3->pRight=node5;
*//*

*//*
    FindMaxLen(node1);
    std::cout<<"nMaxLen:\t"<<nMaxLen;*//*

}*/


