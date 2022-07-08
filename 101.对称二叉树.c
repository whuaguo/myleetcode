/*
 * @lc app=leetcode.cn id=101 lang=c
 *
 * [101] 对称二叉树
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

bool isMirror(struct TreeNode *root1, struct TreeNode *root2)
{
    if (!root1 && !root2)
    {
        return true;
    }

    if (!root1 || !root2 || root1->val != root2->val)
    {
        return false;
    }

    return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
}

bool isSymmetric(struct TreeNode *root)
{
    return isMirror(root->left, root->right);
}
// @lc code=end
