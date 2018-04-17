/**
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any
 node in the tree along the parent-child connections. The path must contain at least one node
 and does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
 */

#include "add.h"



/*
 * 考虑两种情况，经过root和不经过root，如果经过root则计算左右子树的径向PathSum再相加再加上root.val
 * 如果不经过root则递归地计算左右子树的pathSum再比较大小
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        sum = INT_MIN;
        pathSum(root);
        return sum;
    }
private:
    int sum;
    int pathSum(TreeNode* node) {
        if (!node) return 0;
        int left = max(0, pathSum(node -> left));
        int right = max(0, pathSum(node -> right));
        sum = max(sum, left + right + node -> val);
        return max(left, right) + node -> val;
    }
};

/*
 * 这里的pathSum等于是只计算径向的和，因为return的写法
 * 但是在计算sum时，把left，right，以及root.val都加起来了，
 * 又由于递归实际上是自底向上（自上向下展开）开始计算的，实际上sum保存了所有的结点作为top节点可能性中最大的值
 */