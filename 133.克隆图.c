/*
 * @lc app=leetcode.cn id=133 lang=c
 *
 * [133] 克隆图
 */

// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

struct Node *cloneGraph(struct Node *s) {
    if (s == NULL) {
        return NULL;
    }

    struct Node* allNodeList[300] = {0};
    int value2idx[300] = {0};
	int allNodeNum = 1;
    int levelCount = 1;
    allNodeList[0] = s;
    value2idx[s->val] = 1;

    while (levelCount) {
        int base = allNodeNum - levelCount;
        int newLevelCount = 0;

        for (int i = 0; i < levelCount; i++) {
            struct Node* p = allNodeList[base++];
            for (int j = 0; j < p->numNeighbors; j++ ) {
                struct Node *node = p->neighbors[j]; 
                if (value2idx[node->val]) {
                    continue;
                }

                allNodeList[allNodeNum++] = node;
                value2idx[node->val] = allNodeNum; 
                newLevelCount++;
            }
        }

        levelCount = newLevelCount;
    }

    struct Node *newNodeList[300] = {0};
    int newvalue2idx[300] = {0};
    int newNodeNum = 0;
    struct Node * cloneNode;
    struct Node * newNode;

    for (int idx = 0; idx < allNodeNum; idx++) {
        cloneNode = allNodeList[idx];

        newNode = malloc(sizeof(struct Node));
        assert(newNode);

        newNode->val = cloneNode->val;
        newNode->numNeighbors = cloneNode->numNeighbors;
        newNode->neighbors = malloc(cloneNode->numNeighbors * (sizeof(struct Node*)));
        assert(newNode->neighbors);

        newNodeList[newNodeNum++] = newNode;
        newvalue2idx[newNode->val] = newNodeNum;
    }

    for (int idx = 0; idx < allNodeNum; idx++) {
        struct Node * node = newNodeList[idx];
        struct Node ** allNeighbors = allNodeList[idx]->neighbors;
        int numNeighbors = node->numNeighbors;

        for (int i = 0; i < numNeighbors; i++) {
            node->neighbors[i] = newNodeList[newvalue2idx[allNeighbors[i]->val] - 1];
        }
    }

    return newNodeList[0];
}
// @lc code=end

