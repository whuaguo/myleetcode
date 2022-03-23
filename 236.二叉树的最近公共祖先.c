/*
 * @lc app=leetcode.cn id=236 lang=c
 *
 * [236] 二叉树的最近公共祖先
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
#define recordPath                                                                     \
    if ((pNode == p) || (pNode == q))                                                  \
    {                                                                                  \
        if (visitPath == visitPath1)                                                   \
        {                                                                              \
            path1Size = visitPath;                                                     \
            memcpy(visitPath2, visitPath1, visitPathSize * sizeof(struct TreeNode *)); \
            visitPath = visitPath2;                                                    \
        }                                                                              \
        else                                                                           \
        {                                                                              \
            path2Size = visitPathSize;                                                 \
            goto comparePath;                                                          \
        }                                                                              \
    }

struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q)
{
    struct TreeNode *stack[100];
    int stackSize = 0;
    struct TreeNode *pNode = root;

    struct TreeNode **visitPath;
    int visitPathSize = 0;
    struct TreeNode *visitPath1[200];
    struct TreeNode *visitPath2[200];
    int path1Size;
    int path2Size;

    visitPath = visitPath1;
    while (stackSize || pNode)
    {
        while (!pNode && stackSize)
        {
            pNode = stack[stackSize - 1];
            stackSize--;
            visitPathSize--;
            pNode = pNode->right;
        }

        if (pNode)
        {
            while (pNode->left)
            {
                stack[stackSize++] = pNode;
                visitPath[visitPathSize++] = pNode;
                recordPath;
                pNode = pNode->left;
            }

            visitPath[visitPathSize++] = pNode;
            recordPath;

            pNode = pNode->right;
        }
    }

comparePath:

    return heap[0];
}
// @lc code=end
