/*
 * @lc app=leetcode.cn id=99 lang=c
 *
 * [99] 恢复二叉搜索树
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
bool findAbnormalNode(struct TreeNode *root,
                      struct TreeNode **pPrev,
                      struct TreeNode **pNode1,
                      struct TreeNode **pNode2)
{
    if (root->left)
    {
        //左子树寻找
        if (findAbnormalNode(root->left, pPrev, pNode1, pNode2))
        {
            return true;
        }
    }

    if ((*pPrev) && ((*pPrev)->val > root->val))
    {
        //前一个节点比当前节点大，必然是交换节点的情况
        *pNode2 = root;
        if (*pNode1)
        {
            //第一个节点不为空，那么root肯定是第二个节点，找到所有节点，返回
            return;
        }

        //第一个节点为空，代表第一次碰到，那么前一个节点肯定是需要寻找的第一个节点。
        *pNode1 = *pPrev;
    }

    //设置前一个节点
    *pPrev = root;

    if (root->right)
    {
        //右子树寻找
        if (findAbnormalNode(root->right, pPrev, pNode1, pNode2))
        {
            return true;
        }
    }

    return false;
}

void recoverTree(struct TreeNode *root)
{
    struct TreeNode *pPrev = NULL;
    struct TreeNode *pLeft = NULL;
    struct TreeNode *pRight = NULL;

    findAbnormalNode(root, &pPrev, &pLeft, &pRight);

    int save = pLeft->val;
    pLeft->val = pRight->val;
    pRight->val = save;

    return;
}
// @lc code=end
