/*
 * @lc app=leetcode.cn id=94 lang=c
 *
 * [94] 二叉树的中序遍历
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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void addValToList(struct TreeNode* root, int* vals, int* size) {
    if (root->left) {
        addValToList(root->left, vals, size);
    }

    vals[*size] = root->val;
    *size = *size + 1;

    if (root->right) {
        addValToList(root->right, vals, size);
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int vals[101];
    int size = 0;
    int *ret;

    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    addValToList(root, vals, &size);

    *returnSize = size;
    ret = malloc(size * sizeof(int));
    if (ret == NULL) {
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        ret[i] = vals[i];
    }

    return ret;
}
// @lc code=end

