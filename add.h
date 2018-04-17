//
// Created by 刘敬 on 18/3/3.
//

#ifndef LEETCODE_ADD_H
#define LEETCODE_ADD_H

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};


#endif //LEETCODE_ADD_H
