/*
 * @lc app=leetcode.cn id=98 lang=c
 *
 * [98] 验证二叉搜索树
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

bool getBSTmm(struct TreeNode* root, int *min, int*max) {
    if (root) {
        bool ret;

        if (root->left) {
            int lmin;
            int lmax;
            ret = getBSTmm(root->left, &lmin, &lmax);
            if ((ret == false) || (lmax >= root->val) ) {
                return false;
            }
            *min = lmin;
        } else { 
            *min = root->val;
        }

        if (root->right) {
            int rmin;
            int rmax;
            ret = getBSTmm(root->right, &rmin, &rmax);
            if ((ret == false) || (rmin <= root->val) ) {
                return false;
            }

            *max = rmax;
        } else {
            *max = root->val;
        }
    }

    return true;
}

bool isValidBST(struct TreeNode* root){
    int min, max;

    return getBSTmm(root, &min, &max);
}
// @lc code=end

