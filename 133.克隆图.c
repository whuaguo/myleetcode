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
    struct Node* value2node[300] = {0};
	int allNodeNum = 1;
    int levelCount = 1;
    allNodeList[0] = s;
    value2node[s->val] = s;

    while (levelCount) {
        int base = allNodeNum - levelCount;
        int newLevelCount = 0;

        for (int i = 0; i < levelCount; i++) {
            struct Node* p = allNodeList[base++];
            for (int j = 0; j < p->numNeighbors; j++ ) {
                struct Node *node = p->neighbors[j]; 
                if (value2node[node->val]) {
                    continue;
                }

                allNodeList[allNodeNum++] = node;
                value2node[node->val] = node; 
                newLevelCount++;
            }
        }

        levelCount = newLevelCount;
    }

    struct Node *newNodeList[300] = {0};
    struct Node *newvalue2node[300] = {0};
    int newNodeNum = 0;
    for (int idx = 0; idx < allNodeNum; idx++) {
        struct Node * cloneNode = allNodeList[idx];
        
        struct Node * newNode = malloc(sizeof(struct Node));
        assert(newNode);
        newNode->val = cloneNode->val;
        newNode->numNeighbors = cloneNode->numNeighbors;
        newNode->neighbors = malloc(cloneNode->numNeighbors * (sizeof(struct Node*)));
        assert(newNode->neighbors);

        newNodeList[newNodeNum++] = newNode;
        newvalue2node[newNode->val] = newNode;
    }

    for (int idx = 0; idx < allNodeNum; idx++) {
        struct Node * node = newNodeList[idx];

        for (int i = 0; i < allNodeList[idx]->numNeighbors; i++) {
            node->neighbors[i] = newvalue2node[allNodeList[idx]->neighbors[i]->val];
        }
    }

    return newNodeList[0];
}
// @lc code=end

