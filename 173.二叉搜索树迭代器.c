/*
 * @lc app=leetcode.cn id=173 lang=c
 *
 * [173] 二叉搜索树迭代器
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



typedef struct {
    struct TreeNode ** nodes;
    int total;
    int idx;
} BSTIterator;

void bSTNodesToList(struct TreeNode *root, int *num, struct TreeNode **nodes) {
    if (root == NULL) {
        return;
    }

    if (root->left) {
        bSTNodesToList(root->left, num, nodes);
    }

    nodes[*num] = root;
    *num = *num + 1;

    if (root->right) {
        bSTNodesToList(root->right, num, nodes);
    }
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    struct TreeNode * allNodes[10000];
    int nodesNum = 0;

    bSTNodesToList(root, &nodesNum, allNodes);

    BSTIterator *ret = malloc(sizeof(BSTIterator));
    assert (ret);

    ret->nodes = malloc(sizeof(struct TreeNode *) * nodesNum);
    assert (ret->nodes);

    memcpy(ret->nodes, allNodes, sizeof(struct TreeNode *) * nodesNum);
    ret->total = nodesNum;
    ret->idx = -1;

    return ret;
}

int bSTIteratorNext(BSTIterator* obj) {
    if (!obj) return 0;

    if (obj->idx < (obj->total - 1)) {
        obj->idx ++;
        return obj->nodes[obj->idx]->val;
    } else {
        return 0;
    }
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    if (!obj) return false;

    return (obj->idx < (obj->total - 1));
}

void bSTIteratorFree(BSTIterator* obj) {
    if (obj) {
        free(obj->nodes);
        free(obj);
    }
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/
// @lc code=end

