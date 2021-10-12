/*
 * @lc app=leetcode.cn id=124 lang=c
 *
 * [124] 二叉树中的最大路径和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxv = 0x80000000;

int maxLinePathSum(struct TreeNode* root){
    if (!root) {
        return 0;
    }

    if (!root->right && !root->left) {
        return root->val;
    }

    int lpath = -2000;
    int rpath = -2000;

    if (root->left) {
        lpath = maxLinePathSum(root->left);
    }
    
    if (root->right) {
        rpath = maxLinePathSum(root->right);
    }

    //取子树的较大值
    int childpath = ((lpath > rpath) ? lpath : rpath);

    //如果较大值大于0，那么返回当前节点值+这个值，否则不加，这个值是带节点的最大值
    int ret = root->val + ((childpath > 0)?childpath:0);

    //不往上回溯了，那么取V形结构，单节点的最大值
    int maxNodev = root->val + lpath + rpath;
    if (childpath > maxNodev) {
        maxNodev = childpath;
    }

    if (maxNodev > maxv) {
        maxv = maxNodev;
    }

    return ret;
}

int maxPathSum(struct TreeNode* root){
    maxv = -2000;
    int maxLinePath = maxLinePathSum(root);

    return (maxLinePath > maxv) ? maxLinePath : maxv;
}
// @lc code=end

