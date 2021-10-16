/*
 * @lc app=leetcode.cn id=138 lang=c
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
    int nodeNum = 0;
    int nodeIdx[100] = {0};
    struct Node * nodeList[1000] = {0};
    struct Node * newNodeList[1000] = {0};
    struct Node * ptr = head;

    if (head == NULL) {
        return NULL;
    }
    
    while (ptr) {
        struct Node* node = malloc(sizeof(struct Node));

        assert(node);
        nodeList[nodeNum] = ptr;
        node->val = ptr->val;

        //前面节点指向后面节点
        if (nodeNum) {
            newNodeList[nodeNum - 1]->next = node;
        }
        newNodeList[nodeNum++] = node;

        ptr = ptr->next;
    }
    newNodeList[nodeNum - 1]->next = NULL;

    ptr = head;
    struct Node *newptr = newNodeList[0];
    while (ptr) {
        int ridx = 0;
        struct Node* rptr = ptr->random;
        
        while (rptr != nodeList[ridx]) {
            ridx++;
        }

        newptr->random = newNodeList[ridx];
        ptr = ptr->next;
        newptr = newptr->next;
    }

    return newNodeList[0];
}
// @lc code=end

