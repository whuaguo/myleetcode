/*
 * @lc app=leetcode.cn id=114 lang=c
 *
 * [114] 二叉树展开为链表
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

//展开并返回尾部节点
struct TreeNode *flattenTree(struct TreeNode *root)
{
    struct TreeNode *tail = root;
    struct TreeNode *left = root->left;
    struct TreeNode *right = root->right;
    if (left)
    {
        //先展开左子树，记住尾结点
        tail = flattenTree(left);
    }

    //把root当成头指针指向左子树展开链表
    root->left = NULL;
    root->right = left;

    if (right)
    {
        //尾部指针指向右子树
        tail->right = right;

        //右子树展开成为链表
        tail = flattenTree(right);
    }

    //返回尾部指针
    return tail;
}

void flatten(struct TreeNode *root)
{
    if (!root)
    {
        return root;
    }

    flattenTree(root);
    return;
}
// @lc code=end
