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

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int vals[101];
    int retSize = 0;
    struct TreeNode * stack[101];
    int stackSize = 0;
    struct TreeNode * ptr = root; 

    while (stackSize || ptr) {
        while ((ptr == NULL) && stackSize) {
            ptr = stack[--stackSize];
            vals[retSize++] = ptr->val;
            ptr = ptr->right;
        }

        while (ptr) {
            stack[stackSize++] = ptr;
            ptr = ptr->left;
        }
    }

    int *ret = malloc(retSize * sizeof(int));
    assert(ret != NULL);

    memcpy(ret, vals, retSize * sizeof(int));
    *returnSize = retSize;
    
    return ret;
}
// @lc code=end

