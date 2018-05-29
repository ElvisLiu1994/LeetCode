//
// Created by 刘敬 on 18/3/28.
//

#include "../add.h"

bool matchCore(const char* str, const char* pattern);

/***************************************************************************/

// 往链表尾部插入一个结点，注意有可能一开始该链表是个空链表
// 需要注意的是这里使用了指针的指针，因为如果传入的只是个指针的话，而该链表一开始为空，即传入的是个nullptr，这时将会
// 改变该指针指向一个新创建的结点，但是呢，指针的参数传递也只是复制了一份该指针，实参数指针的值不会改变，依旧为nullptr。
// 由于可能需要修改指针的值(当传入链表为空时)，所以需要的参数为指针的指针，或者指针的引用也行。
void addToTail(ListNode** pHead, int value){
    ListNode *pNew = new ListNode(0);
    pNew->val = value;
    pNew->next = nullptr;

    if(*pHead == nullptr){
        *pHead = pNew;
    }else{
        ListNode *pNode = *pHead;

        while(pNode->next != nullptr)
            pNode = pNode->next;

        pNode->next = pNew;
    }
}

/***************************************************************************/

// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。



using std::stack;
void PrintListReversingly_Iteratively(ListNode *pHead){

    stack<ListNode *> nodes;

    ListNode *pNode = pHead;
    while(pNode != nullptr){
        pNode = pNode->next;
        nodes.push(pNode);
    }

    while(!nodes.empty()){
        pNode = nodes.top();
        printf("%d\t", pNode->val);
        nodes.pop();
    }
}

void PrintListReversingly_Recursively(ListNode* pHead) {
    if(pHead != nullptr){
        if (pHead->next != nullptr) {
            PrintListReversingly_Recursively(pHead->next);
        }

        printf("%d\t", pHead->val);
    }
}

/***************************************************************************/

// 面试题18（一）：在O(1)时间删除链表结点
// 题目：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该
// 结点。

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted){
    if(!pListHead || ! pToBeDeleted)
        return;
    // 要删除的不是尾节点
    if(pToBeDeleted->next != nullptr){
        ListNode *pNext = pToBeDeleted->next;
        pToBeDeleted->val = pNext->val;
        pToBeDeleted->next = pNext->next;

        delete pNext;
        pNext = nullptr;
    }
    // 删除的是尾节点，并且链表只有一个节点，即删除头节点
    else if(*pListHead == pToBeDeleted){
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
        *pListHead = nullptr;
    }
    // 链表中有多个节点，删除的是尾节点，只能遍历
    else{
        ListNode *pNode = *pListHead;
        while(pNode->next != pToBeDeleted)
            pNode = pNode->next;

        pNode->next = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}

/***************************************************************************/

// 面试题22：链表中倒数第k个结点
// 题目：输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，
// 本题从1开始计数，即链表的尾结点是倒数第1个结点。例如一个链表有6个结点，
// 从头结点开始它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个结点是
// 值为4的结点。

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k){
    if(pListHead == nullptr || k == 0)
        return nullptr;

    ListNode *pAhead = pListHead;
    ListNode *pBehind = nullptr;

    for(int i = 0; i < k-1; i++){
        if(pAhead->next != nullptr)
            pAhead = pAhead->next;
        else
            return nullptr;
    }

    pBehind = pListHead;
    while(pAhead->next != nullptr){
        pAhead = pAhead->next;
        pBehind = pBehind->next;
    }

    return pBehind;
}

/***************************************************************************/

// 面试题23：链表中环的入口结点
// 题目：一个链表中包含环，如何找出环的入口结点？例如，在图3.8的链表中，
// 环的入口结点是结点3。

// 先找到两指针相遇的节点，如果不存在环，那么返回的将是nullptr
ListNode* MeetingNode(ListNode* pHead){
    if(pHead == nullptr)
        return nullptr;

    ListNode* pSlow = pHead->next;
    if(pSlow == nullptr)
        return nullptr;

    ListNode* pFast = pSlow->next;
    while(pSlow != nullptr && pFast != nullptr){
        if(pFast == pSlow)
            return pFast;

        pSlow = pSlow->next;
        pFast = pFast->next;
        if(pFast != nullptr)
            pFast = pFast->next;
    }

    return nullptr;
}

// 找到环中的一个节点之后，循环一圈就能知道环的长度，并能找到环的入口节点
ListNode* EntryNodeOfLoop(ListNode* pHead){
    ListNode* meetingNode = MeetingNode(pHead);
    if(meetingNode == nullptr)
        return nullptr;

    //得到环中的节点数目
    int nodesInLoop = 1;
    ListNode* pNode1 = meetingNode;
    while(pNode1->next != meetingNode){
        nodesInLoop++;
        pNode1 = pNode1->next;
    }

    //先移动pNode1，次数为环中节点的数目
    pNode1 = pHead;
    for(int i = 0; i < nodesInLoop; i++)
        pNode1 = pNode1->next;

    // 再移动pNode1和pNode2，则pNode1和pNode2最终同时指向入口节点
    ListNode* pNode2 = pHead;
    while(pNode1 != pNode2){
        pNode1 = pNode1->next;
        pNode2 = pNode2->next;
    }

    return pNode1;
}

/***************************************************************************/

// 面试题24：反转链表
// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的
// 头结点。

ListNode* ReverseList(ListNode* pHead){

    ListNode* pReversedHead = nullptr;
    ListNode* pNode = pHead;
    ListNode* pPrev = nullptr;
    while(pNode != nullptr){
        ListNode* pNext = pNode->next;

        if(pNext == nullptr)
            pReversedHead = pNode;

        pNode->next = pPrev;
        pPrev = pNode;
        pNode = pNext;
    }

    return pReversedHead;

}

/***************************************************************************/

void list_main(){

}