//
// Created by 刘敬 on 18/4/2.
//

/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
 */

#include "add.h"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *pHead = new ListNode(0);
    ListNode *p = pHead;

    int extra = 0;

    while(l1 || l2 || extra){
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        extra = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }

    return pHead->next;
}

//void _tmain(){
//    ListNode l1(5);
//    ListNode l2(5);
//    ListNode *p = addTwoNumbers(&l1, &l2);
//    cout << p->next->val << endl;
//}