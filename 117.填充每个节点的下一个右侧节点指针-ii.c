/*
 * @lc app=leetcode.cn id=117 lang=c
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
    //空树，返回NULL
    if (!root) {
        return NULL;
    }

    struct Node* nodes1[3000] = {NULL};
    struct Node* nodes2[3000] = {NULL};
    struct Node** fathers = &nodes1;
    struct Node** childrens = &nodes2;
    int fatherCount = 1;

    fathers[0] = root;
    while (fatherCount) {
        struct Node *node;
        int childrenCount = 0;

        //找到一个node的节点
        for (int i = 0; i < fatherCount; i++) {
            node = fathers[i];

            if (node->left) {
                childrens[childrenCount++] = node->left;
            }
            if (node->right) {
                childrens[childrenCount++] = node->right;
            }

            node->next = ((i == (fatherCount -1))? NULL: fathers[i+1]);
        }

        fatherCount = childrenCount;
        struct Node ** buffer = fathers;
        fathers = childrens;
        childrens = buffer;
    }

    return root;
}
// @lc code=end

