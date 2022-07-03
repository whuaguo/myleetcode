/*
 * @lc app=leetcode.cn id=337 lang=c
 *
 * [337] 打家劫舍 III
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
#define MAX(a, b) ((a) > (b) ? (a) : (b))

void do_rob(struct TreeNode *root, int *values)
{
    if (!root)
    {
        return;
    }

    int vleft[2] = {0, 0};
    int vright[2] = {0, 0};

    do_rob(root->left, vleft);
    do_rob(root->right, vright);

    values[0] = MAX(vleft[0], vleft[1]) + MAX(vright[0], vright[1]);
    values[1] = root->val + vleft[0] + vright[0];

    return;
}

int rob(struct TreeNode *root)
{
    if (!root)
        return 0;

    int vals[2] = {0, 0};
    do_rob(root, vals);

    return MAX(vals[0], vals[1]);
}
// @lc code=end
