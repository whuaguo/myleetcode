/*
 * @lc app=leetcode.cn id=106 lang=c
 *
 * [106] 从中序与后序遍历序列构造二叉树
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


struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    struct TreeNode *root;

    //参数不合法，直接返回
    if ((0 == postorderSize) || (postorderSize != inorderSize)) {
        return NULL;
    }

    //构建根节点
    int rootval = postorder[postorderSize - 1];
    root = malloc(sizeof(struct TreeNode));
    if (root == NULL) {
        return NULL;
    }
    root->val = rootval;

    if (postorderSize == 1 ){
        root->left = root->right = NULL;
        return root;
    }

    //在中序数组中找到root的位置,序号就是左边的节点个数
    int leftnum;
    for (leftnum = 0; leftnum < inorderSize; leftnum++) {
        if (inorder[leftnum] == rootval) {
            break;
        }
    }

    //右边的节点个数
    int rightnum = inorderSize - leftnum - 1;

    //递归构建左右树
    root->left = leftnum ? buildTree(inorder, leftnum, postorder, leftnum):NULL;
    root->right = rightnum ? buildTree(inorder + leftnum + 1, rightnum, postorder+leftnum, rightnum) : NULL;    

    return root;
}
// @lc code=end

