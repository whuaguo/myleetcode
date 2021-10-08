/*
 * @lc app=leetcode.cn id=98 lang=c
 *
 * [98] 验证二叉搜索树
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

bool isBSTinRange(struct TreeNode* root, long min, long max) {
    return  root ? 
            ((root->val < max) && (root->val > min) && 
             (root->left ? isBSTinRange(root->left, min, root->val) : true) &&
             (root->right? isBSTinRange(root->right, root->val, max): true)):
        true;
}

bool isValidBST(struct TreeNode* root){
    return isBSTinRange(root, 0x8000000000000000, 0x7fffffffffffffff);
}
// @lc code=end

