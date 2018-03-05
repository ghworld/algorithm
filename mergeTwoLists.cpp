//
// Created by mi on 6/1/17.
//

#include "Utils.h"

typedef struct LNode {
    int val;
    LNode *next;
    LNode(int val) : val(val) {}
} ListNode;

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(-1);
    ListNode *cur = dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    cur->next = l1 ? l1 : l2;
    return dummy->next;
}


/*

int main() {

    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);


    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(7);
    l2->next->next->next = new ListNode(8);


    ListNode *l3 = mergeTwoLists(l1, l2);

    ListNode *tmp = l3;
    while (tmp != NULL) {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }

    delete[] l1;
    delete[] l2;


    return 0;
}
*/


class Solution {
//    merge K Lists
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return NULL;
        int n = lists.size();
        while (n > 1) {
            int k = (n + 1) / 2;
            for (int i = 0; i < n / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            n = k;
        }
        return lists[0];
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return head->next;
    }
};


/*
int main(){
    Solution *s1=new Solution();

}*/
