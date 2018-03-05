#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <iostream>


typedef char ElementType;
typedef struct BTNode {
    ElementType data;
    BTNode *pLchild;
    BTNode *pRchild;
} BTNode, *BTree;

BTree create_tree();

void pre_traverse(BTree);

void in_traverse(BTree);

void beh_traverse(BTree);


BTree create_tree() {
    BTree pA = (BTree) malloc(sizeof(BTNode));
    BTree pB = (BTree) malloc(sizeof(BTNode));
    BTree pC = (BTree) malloc(sizeof(BTNode));
    BTree pD = (BTree) malloc(sizeof(BTNode));
    BTree pE = (BTree) malloc(sizeof(BTNode));
    BTree pF = (BTree) malloc(sizeof(BTNode));
    BTree pG = (BTree) malloc(sizeof(BTNode));
    pA->data = 'A';
    pB->data = 'B';
    pC->data = 'C';
    pD->data = 'D';
    pE->data = 'E';
    pF->data = 'F';
    pG->data = 'G';

    pA->pLchild = pB;
    pA->pRchild = pC;
    pB->pLchild = pD;
    pB->pRchild = pE;
    pD->pLchild = pD->pRchild = NULL;
    pE->pLchild = pD->pRchild = NULL;
    pC->pLchild = pF;
    pC->pRchild = pG;
//    pC->pRchild = NULL;
    pF->pLchild = pF->pRchild = NULL;

    return pA;
}


void pre_traverse(BTree pTree) {
    if (pTree) {
        printf("%c ", pTree->data);
        if (pTree->pLchild) {
            pre_traverse(pTree->pLchild);
        }
        if (pTree->pRchild) {
            pre_traverse(pTree->pRchild);
        }
    }
}

void in_traverse(BTree pTree) {
    if (pTree) {
        if (pTree->pLchild)
            in_traverse(pTree->pLchild);
        printf("%c ", pTree->data);
        if (pTree->pRchild)
            in_traverse(pTree->pRchild);
    }
}

void beh_traverse(BTree pTree) {
    if (pTree) {
        if (pTree->pLchild)
            beh_traverse(pTree->pLchild);
        if (pTree->pRchild)
            beh_traverse(pTree->pRchild);
        printf("%c ", pTree->data);
    }
}


BTree inverTree(BTree tree) {
    if (tree == NULL) {
        return tree;
    }

    BTree tmp = tree->pLchild;
    tree->pLchild = tree->pRchild;
    tree->pRchild = tmp;

    inverTree(tree->pLchild);
    inverTree(tree->pRchild);

    return tree;

}

//下面是非递归遍历

using std::stack;

void PreOrderTraverse(BTree T)//非递归先序遍历
{

    stack<BTree> Stack;
    if (!T) {
        printf("空树！\n");
        return;
    }
    while (T || !Stack.empty()) {
        while (T) {
            Stack.push(T);
            printf("%c", T->data);
            T = T->pLchild;
        }
        T = Stack.top();
        Stack.pop();
        T = T->pRchild;
    }
}



//非递归 反转二叉树；

BTree InvertTree(BTree tree) {

    if (tree == NULL) {
        return tree;
    }
    stack<BTree> stack;
    stack.push(tree);
    while (!stack.empty()) {
        BTree  top=stack.top();
        stack.pop();

        BTree tmp=top->pLchild;
        top->pLchild=top->pRchild;
        top->pRchild=tmp;
        if(top->pLchild) stack.push(top->pLchild);
        if(top->pRchild) stack.push(top->pRchild);

    }

    return tree;

}


/*
int main() {

    BTree tree = create_tree();
//递归Demo:

//    inverTree(tree);
    pre_traverse(tree);
    std::cout<<"\n";

    InvertTree(tree);
    pre_traverse(tree);
//    in_traverse(tree);

//    非递归Demo:
//    PreOrderTraverse(tree);



}*/
