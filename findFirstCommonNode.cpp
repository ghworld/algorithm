//
// Created by mi on 4/13/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>


using namespace std;


typedef struct LNode {
    int val;
    LNode *next;

    LNode(int x) : val(x), next(NULL) {}
} ListNode, *LinkList;


void printLinkList(LinkList linkList) {
    LinkList llist = linkList;

    while (llist != NULL) {
        cout << "the value is :\t" << llist->val << endl;
        llist = llist->next;
    }
}


int getListLength(LinkList pHead) {
    int len = 0;
    LinkList pNode = pHead;

    while (pNode != NULL) {
        len++;
        pNode = pNode->next;
    }
    return len;
}


LNode *findFirstCommonNode(LinkList pHead1, LinkList pHead2) {
    int len1 = getListLength(pHead1);
    int len2 = getListLength(pHead2);
    int diff = len1 - len2;
    LinkList headLong=pHead1;
    LinkList headShort=pHead2;

    if (diff < 0) {
        headLong=pHead2;
        headShort=pHead1;
        diff=len2-len1;
    }

    for(int i =0; i<diff ;i++){
        headLong=headLong->next;
    }

    while (headLong!=NULL && headShort!=NULL && headLong!=headShort){
        headLong=headLong->next;
        headShort=headShort->next;

    }

    ListNode* commonNode=headLong;
    return commonNode;

}

/*
int main() {

    LNode *node1 = new LNode(10);
    LNode *node2 = new LNode(11);
    LNode *node3 = new LNode(12);
    LNode *node4 = new LNode(13);


    LinkList linkList = node1;
    linkList->next = node2;
    linkList->next->next = node3;

    LinkList linkList2 = node3;
    linkList2->next = node4;


    printLinkList(linkList);


    cout<<findFirstCommonNode(linkList,linkList2)->val;


//    cout << "===============" << endl;
//    int len = getListLength(linkList);
//    cout << "the len is :\t" << len << endl;


}
 */

