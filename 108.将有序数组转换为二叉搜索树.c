/*
 * @lc app=leetcode.cn id=108 lang=c
 *
 * [108] 将有序数组转换为二叉搜索树
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
struct TreeNode *sortListToBST(int *nums, int from, int to)
{
    int mid = (from + to) >> 1;
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    assert(root != NULL);

    root->val = nums[mid];
    root->left = (from < mid) ? sortListToBST(nums, from, mid - 1) : NULL;
    root->right = (mid < to) ? sortListToBST(nums, mid + 1, to) : NULL;

    return root;
}

struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
    if (!numsSize)
    {
        return NULL;
    }

    return sortListToBST(nums, 0, numsSize - 1);
}
// @lc code=end
