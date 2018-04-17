//
// Created by 刘敬 on 18/3/28.
//

#include "../add.h"

/***************************************************************************/

TreeNode* helper(vector<int>&, int, int, vector<int>&, int, int);

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    return helper(preorder,0,preorder.size(),inorder,0,inorder.size());

}

TreeNode* helper(vector<int>& preorder,int i,int j,vector<int>& inorder,int ii,int jj)
{
    // tree        8 4 5 3 7 3
    // preorder    8 [4 3 3 7] [5]
    // inorder     [3 3 4 7] 8 [5]

    // 每次从 preorder 头部取一个值 mid，作为树的根节点
    // 检查 mid 在 inorder 中 的位置，则 mid 前面部分将作为 树的左子树，右部分作为树的右子树

    if(i >= j || ii >= j)
        return nullptr;

    int inIndex = 0;
    for(int k = ii; k < jj; k++){
        if(inorder[k] == preorder[i])
            inIndex = k;
    }

    int dis = inIndex - ii;

    TreeNode* root = new TreeNode(preorder[i]);
    root -> left = helper(preorder,i + 1,i + 1 + dis,inorder,ii,ii + dis);
    root -> right = helper(preorder,i + 1 + dis,j,inorder,ii + dis + 1,jj);
    return root;
}

/***************************************************************************/



