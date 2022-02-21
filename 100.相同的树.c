/*
 * @lc app=leetcode.cn id=100 lang=c
 *
 * [100] 相同的树
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


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (!p && !q) {
        return true;
    }

    if (((p && !q)) ||(q && !p)) {
        return false;
    }

    struct TreeNode * stack[10][2];
    int stackSize = 0;

    while (stackSize || p) {
        while (!p && stackSize) {
            stackSize--;
            p = stack[stackSize][0];
            q = stack[stackSize][1];
            p = p->right;
            q = q->right;
        }

        while (p && q) {
            if (p->val != q->val) {
                return false;
            }

            stack[stackSize][0] = p;
            stack[stackSize][1] = q;
            stackSize++;
            p = p->left;
            q = q->left;
        }

        if (q != p) {
            return false;
        }
    }

    return true;
}
// @lc code=end

