/*
 * @lc app=leetcode.cn id=129 lang=c
 *
 * [129] 求根节点到叶节点数字之和
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

int sumNumbersWithBase(struct TreeNode *root, int base){
    if (root == NULL) {
        return 0;
    }

    int newBase = base * 10 + root->val;    
    if (!root->left && !root->right) {
        return newBase;
    }

    int sumleft = sumNumbersWithBase(root->left, newBase);
    int sumright = sumNumbersWithBase(root->right, newBase);

    return sumleft+sumright;
}

int sumNumbers(struct TreeNode* root){
    return sumNumbersWithBase(root, 0);
}
// @lc code=end

