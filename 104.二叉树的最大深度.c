/*
 * @lc app=leetcode.cn id=104 lang=c
 *
 * [104] 二叉树的最大深度
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


int maxDepth(struct TreeNode* root){
    int lmax, rmax;
    if (root == NULL) {
        return 0;
    }
    
    lmax = maxDepth(root->left);
    rmax = maxDepth(root->right);

    return 1 + ((lmax>rmax)?lmax:rmax);
}
// @lc code=end

