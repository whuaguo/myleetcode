/*
 * @lc app=leetcode.cn id=107 lang=c
 *
 * [107] 二叉树的层序遍历 II
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    struct TreeNode* nodeStack[2000] = {NULL};
    int levelSizeStack[1000] = {0};
    int nodeStackDepth = 0;
    int levelDepth = 0;

    //空树，返回NULL
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    //把根节点推入栈
    nodeStack[nodeStackDepth++] = root;
    levelSizeStack[levelDepth++] = 1;

    //从栈中取出上一级node个数
    int levelNodeCount = 1;
    while (levelNodeCount) {
        //找到一个node的节点
        int leveNodeStackIdx = nodeStackDepth - levelNodeCount;
        int levelChildCount = 0;    //记录上一级节点的子节点个数
        for (int i = 0; i < levelNodeCount; i++) {
            struct TreeNode *node = nodeStack[leveNodeStackIdx++];

            if (node->left) {
                levelChildCount++;
                nodeStack[nodeStackDepth++] = node->left;
            }
            if (node->right) {
                levelChildCount++;
                nodeStack[nodeStackDepth++] = node->right;
            }
        }

        levelNodeCount = levelChildCount;
        if (levelChildCount) {
            //记录这一层级的节点个数，
            levelSizeStack[levelDepth++] = levelChildCount;
        }
    }

    //根据层级分配返回数组和每个数组长度的内存
    int **ret = malloc(sizeof(int *) * levelDepth);
    int *retColSize = malloc(sizeof(int) * levelDepth);

    assert(ret && retColSize);
    *returnSize = levelDepth;
    *returnColumnSizes = retColSize;

    int levelIdx = 0;
    int levelCount = 0;
    for (int i = levelDepth - 1; i >= 0; i--) {
        levelCount = levelSizeStack[i];
        nodeStackDepth -= levelCount;

        //分配这一层级的val数组，并取值
        int* vals = malloc(sizeof(int) * levelCount);
        retColSize[levelIdx] = levelCount;
        ret[levelIdx++] = vals;

        assert(vals);
        for (int j = nodeStackDepth; levelCount > 0 ;levelCount--,j++) {
            vals[j - nodeStackDepth] = nodeStack[j]->val;
        }
    }

    return ret;
}
// @lc code=end

