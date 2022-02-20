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
    struct TreeNode * ptrp = p;
    struct TreeNode * ptrq = q; 

    while (stackSize || ptrp) {
        while ((ptrp == NULL) && stackSize) {
            stackSize--;
            ptrp = stack[stackSize][0];
            ptrq = stack[stackSize][1];
            ptrp = ptrp->right;
            ptrq = ptrq->right;
        }

        while (ptrp && ptrq) {
            if (ptrp->val != ptrq->val) {
                return false;
            }
            stack[stackSize][0] = ptrp;
            stack[stackSize][1] = ptrq;
            stackSize++;
            ptrp = ptrp->left;
            ptrq = ptrq->left;
        }

        if (ptrq != ptrp) {
            return false;
        }
    }

    return true;
}
// @lc code=end

