/*
 * @lc app=leetcode.cn id=24 lang=c
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *phead = NULL;
    struct ListNode *ptail = NULL;
    struct ListNode *p1 = head;
    struct ListNode *p2;

    if ((head == NULL) || (head->next == NULL)) {
        return head;
    }

    while (p1 && p1->next) {
        p2 = p1->next;
        p1->next = p2->next;
        p2->next = p1;

        if (phead == NULL) {
            phead = p2;
        }

        if (ptail) {
            ptail->next = p2;
        }

        ptail = p1;
        p1 = p1->next;
        p2 = p1? p1->next:NULL;
    }

    return phead;
}
// @lc code=end

