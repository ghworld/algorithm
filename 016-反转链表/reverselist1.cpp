//
// Created by mi on 8/8/18.
//

#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
};


class Solution {
    ListNode *ReverseList(ListNode *pHead) {
        ListNode *pNode = pHead;  //当前结点
        ListNode *pPrev = NULL;
        ListNode *pNext = NULL;

        while (pNode != NULL) {
            pNext = pNode->next;  //下一个节点
            pNode->next = pPrev;  //指向闰一节点
            pPrev = pNode;
            pNode = pNext;
        }
        return pPrev;
    }
};

//其实这个也是第一次写,还是多写多想,搞明白,众头到尾能够讲清楚


//int main(){
//    ListNode list[5];
//    list[0].val = 1;
//    list[0].next = &list[1];
//    list[1].val = 2;
//    list[1].next = &list[2];
//    list[2].val = 3;
//    list[2].next = &list[3];
//    list[3].val = 4;
//    list[3].next = &list[4];
//    list[4].val = 5;
//    list[4].next = NULL;
//
//
//    ListNode *node = list;
//    while(node != NULL)
//    {
//        cout <<node->val<<"\t";
//        node = node->next;
//    }
//    cout <<endl;
//
//    Solution solu;
//    node = solu.ReverseList(list);
//    while(node != NULL)
//    {
//        cout <<node->val<<"\t";
//        node = node->next;
//    }
//    cout <<endl;
//
//    return 0;
//
//}