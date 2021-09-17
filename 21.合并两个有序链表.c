/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    struct ListNode *retp = NULL;
    struct ListNode *op = NULL;

    if (!p1 || !p2 ) {
        return p1?p1:p2;
    }

    //get the small one head, it will be the return node.
    retp = (p1->val >p2->val)? p2:p1;

    //the last one node;
    op = retp;

    //move out the head
    if (retp == p1) {
        p1 = p1->next;
    } else {
        p2 = p2->next;
    }

    //add the small nodes in the p1&p2 to the op one by one.
    while (p1 || p2) {
        //p1 or p2 is empty, add all non-empty one to op
        if (!p1 || !p2) {
            op->next = p1?p1:p2;
            break;
        }

        if (p1->val <= p2->val) {
            op->next = p1;
            p1 = p1->next;
        } else {
            op->next = p2;
            p2 = p2->next;
        }
        op = op->next;
    }

    return retp;
}
// @lc code=end

