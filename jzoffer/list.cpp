//
// Created by 刘敬 on 18/3/28.
//

#include "../add.h"

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

int list_main(){

}