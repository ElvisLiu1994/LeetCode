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

// 面试题19：正则表达式匹配
// 题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'
// 表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题
// 中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"
// 和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。

bool matchCore(const char* str, const char* pattern);

bool match(const char* str, const char* pattern)
{
    if(str == nullptr || pattern == nullptr)
        return false;

    return matchCore(str, pattern);
}

bool matchCore(const char* str, const char* pattern){

    if(*str == '\0' && *pattern == '\0')
        return true;

    if(*str != '\0' && *pattern == '\0')
        return false;

    if(*(pattern + 1) == '*'){
        if(*pattern == *str || (*pattern == '.' && *str != '\0'))
            return matchCore(str+1, pattern+2) || matchCore(str+1, pattern) || matchCore(str, pattern+2);
        else
            return matchCore(str, pattern+2);
    }

    if(*str == *pattern || (*pattern == '.' && *str != '\0'))
        return matchCore(str+1, pattern+1);

    return false;
}
/***************************************************************************/

void list_main(){
    char* str = "aaa";
    char* pattern = "aaaa";
    cout << match(str, pattern) << endl;
}