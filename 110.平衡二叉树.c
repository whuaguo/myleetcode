/*
 * @lc app=leetcode.cn id=110 lang=c
 *
 * [110] 平衡二叉树
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

bool getBalancedHeight(struct TreeNode *root, short *h) {
    //空节点，返回
    if (root == NULL) {
        *h = 0;
        return true;
    }

    //单节点，返回
    if (!root->left && !root->right) {
        *h = 1;
        return true;
    }

    //一边节点为空，另外一边不为空，且有孩子节点，直接返回错误
    if (!root->left && root->right && (root->right->left || root->right->right) ||
        !root->right && root->left && (root->left->left || root->left->right))
    {
            return false;
    }

    //分别取得左右节点的高度
    bool lbalanced = true;
    bool rbalanced = true;
    short lheight = 0;
    short rheight = 0;
    if (root->left) {
        lbalanced = getBalancedHeight(root->left, &lheight);
    }

    if (root->right) {
        rbalanced = getBalancedHeight(root->right, &rheight);
    }

    //两边都是平衡子树，且左右高度相差小于1， 返回正确高度
    if (lbalanced && rbalanced) {
        if ((lheight > rheight) && (lheight - rheight <= 1) ||
            (rheight >= lheight) && (rheight - lheight <= 1)) 
        {
            *h = 1 + ((lheight > rheight)?lheight:rheight);
            return true;
        }
    } 

    //其他情况统统代表不平衡
    return false;
}

bool isBalanced(struct TreeNode* root){
    short rootheight;
    return getBalancedHeight(root, &rootheight);
}
// @lc code=end

