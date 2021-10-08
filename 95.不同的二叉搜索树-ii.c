/*
 * @lc app=leetcode.cn id=95 lang=c
 *
 * [95] 不同的二叉搜索树 II
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

/*
 * 如果数目0，二叉树个数1 (null) f(0)
 * 如果数目1，二叉树个数1 (val)  f(1)
 * 如果数目n, 二叉树个数计算方式：
 *   根为1，左树[ ]，右树为[2,n]
 *   根为2，左数[1]，右树为[3,n]
 *   根为n, 左树[1, n-1]，右树[ ]
 *   总数f(n) = f(0) * f(n-1) + f(1) * f(n-2) + ... +f(n-1) * f(0)
 */
static int treeSize[9] = {1,1,0,0,0,0,0,0,0};
static void initSizeArray(int n) {
    if (n > 9) {
        n = 9;
    }

    for (int i = 2; i <= n; i ++) {
        int total = 0;

        for (int j = 0; j < i; j ++) {
            total += treeSize[j]*treeSize[i-1-j];
        }

        treeSize[i] = total;
    }
}

//初始化一个节点
static inline struct TreeNode* generateTreeNode(int val) {
    struct TreeNode *node;

    node =  malloc(sizeof(struct TreeNode));
    if (node) {
        node->val = val;
    }
    
    return node;
}

#define generateTreeList(size) malloc(sizeof(struct TreeNode *) * size)
#define getTreeSize(n) treeSize[n]

//得到所有二叉树，排序从min到Max
struct TreeNode** generateTreesFromRange(int min, int max, int* size) {
    struct TreeNode **nodeList;
    struct TreeNode *root;

    *size = getTreeSize(max - min + 1);   //可能的总数
    nodeList = generateTreeList(*size);   //节点数组
    if (!nodeList) {
        return NULL;
    }

    //只有一个节点，直接初始化节点和数组，然后返回
    if (min == max) {
        root = generateTreeNode(min);
        if (root) {
            root->left = NULL;
            root->right = NULL;
        }

        nodeList[0] = root;
        return nodeList;
    }

    //根节点的取值从min到max
    int idx = 0;                          
    for (int rootVal = min; rootVal <= max; rootVal++) {
        struct TreeNode** leftList = NULL;
        struct TreeNode** rightList = NULL;
        int leftSize = 1;
        int rightSize = 1;

        //左树数组
        if (rootVal > min) {
            leftList = generateTreesFromRange(min, rootVal - 1, &leftSize);
        }

        //右树数组
        if (rootVal < max) {
            rightList = generateTreesFromRange(rootVal + 1, max, &rightSize);
        }

        //可能的组合方式
        for (int lidx = 0; lidx < leftSize; lidx++) {
            for (int ridx = 0; ridx < rightSize; ridx++) {
                root =  generateTreeNode(rootVal);
                if (root ) {
                    nodeList[idx++] = root;
                    root->left = leftList ? leftList[lidx] : NULL;
                    root->right = rightList ? rightList[ridx] : NULL;
                }
            }
        }

        //用完之后可以释放左树和右树的数组，节点不用释放
        if (leftList) {
            free(leftList);
        }

        if (rightList) {
            free(rightList);
        }
    }

    return nodeList;
}

struct TreeNode** generateTrees(int n, int* returnSize){
    initSizeArray(n);

    return generateTreesFromRange(1, n, returnSize);
}
// @lc code=end

