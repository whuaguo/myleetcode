/*
 * @lc app=leetcode.cn id=111 lang=c
 *
 * [111] 二叉树的最小深度
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


int minDepth(struct TreeNode* root){
    //空树，返回NULL
    if (!root) {
        return 0;
    }

    struct TreeNode* nodes1[500] = {NULL};
    struct TreeNode* nodes2[500] = {NULL};
    struct TreeNode** fathers = &nodes1;
    struct TreeNode** childrens = &nodes2;
    int depth = 1;
    int fatherCount = 1;

    fathers[0] = root;
    while (fatherCount) {
        int childrenCount = 0;

        //找到一个node的节点
        for (int i = 0; i < fatherCount; i++) {
            struct TreeNode *node = fathers[i];

            if (!node->left && !node->right) {
                return depth;
            }

            if (node->left) {
                childrens[childrenCount++] = node->left;
            }
            if (node->right) {
                childrens[childrenCount++] = node->right;
            }
        }

        fatherCount = childrenCount;
        struct TreeNode ** buffer = fathers;
        fathers = childrens;
        childrens = buffer;

        depth++;
    }

    return depth;
}
// @lc code=end

