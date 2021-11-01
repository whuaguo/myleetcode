<<<<<<< HEAD
/*
 * @lc app=leetcode.cn id=199 lang=c
 *
 * [199] 二叉树的右视图
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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize){
    //边界检查
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    struct TreeNode*  stack1[100] = {0};
    struct TreeNode*  stack2[100] = {0};
    struct TreeNode** fathers = stack1;     //父亲节点集合
    struct TreeNode** children = stack2;    //孩子节点集合
    int father_count = 1;                   //初始父亲节点为1， root
    int children_count = 0;                 //初始孩子节点未知

    int buffer[100] = {0};                  //答案缓存
    int buffer_idx = 0;                     //答案长度

    fathers[0] = root;
    while (father_count) {
        //取最后一个父亲节点的值
        buffer[buffer_idx++] = fathers[father_count - 1]->val;

        //孩子节点收集
        children_count = 0;
        for (int idx = 0; idx < father_count; idx++) {
            if (fathers[idx]->left)
                children[children_count++] = fathers[idx]->left;

            if (fathers[idx]->right)
                children[children_count++] = fathers[idx]->right;
        }

        //孩子节点变成父亲节点
        struct TreeNode** stack_buffer = fathers;
        fathers = children;
        children = stack_buffer;
        father_count = children_count;
    }

    //申请内存，拷贝答案
    int * ret = malloc(sizeof(int) * buffer_idx);
    assert(ret);
    memcpy(ret, buffer, sizeof(int)*buffer_idx);
    *returnSize = buffer_idx;

    return ret;
}
// @lc code=end

=======
/*
 * @lc app=leetcode.cn id=199 lang=c
 *
 * [199] 二叉树的右视图
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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize){
    //边界检查
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    struct TreeNode*  stack1[100] = {0};
    struct TreeNode*  stack2[100] = {0};
    struct TreeNode** fathers = stack1;     //父亲节点集合
    struct TreeNode** children = stack2;    //孩子节点集合
    int father_count = 1;                   //初始父亲节点为1， root
    int children_count = 0;                 //初始孩子节点未知

    int buffer[100] = {0};                  //答案缓存
    int buffer_idx = 0;                     //答案长度

    fathers[0] = root;
    while (father_count) {
        //取最后一个父亲节点的值
        buffer[buffer_idx++] = fathers[father_count - 1]->val;

        //孩子节点收集
        children_count = 0;
        for (int idx = 0; idx < father_count; idx++) {
            if (fathers[idx]->left)
                children[children_count++] = fathers[idx]->left;

            if (fathers[idx]->right)
                children[children_count++] = fathers[idx]->right;
        }

        //孩子节点变成父亲节点
        struct TreeNode** stack_buffer = fathers;
        fathers = children;
        children = stack_buffer;
        father_count = children_count;
    }

    //申请内存，拷贝答案
    int * ret = malloc(sizeof(int) * buffer_idx);
    assert(ret);
    memcpy(ret, buffer, sizeof(int)*buffer_idx);
    *returnSize = buffer_idx;

    return ret;
}
// @lc code=end

>>>>>>> b9e17ed08f68eccf15d14565f758e023fbb7ed3d
