/*
 * @lc app=leetcode.cn id=112 lang=c
 *
 * [112] 路径总和
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
bool hasPathSum(struct TreeNode* root, int targetSum){
    if (root == NULL) {
        return false;
    }

    if (!root->left && !root->right) {
        return (targetSum == root->val);
    }

    return hasPathSum(root->left, targetSum - root->val) || 
           hasPathSum(root->right, targetSum - root->val);
}
// @lc code=end

