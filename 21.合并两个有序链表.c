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

    retp = (p1->val >p2->val)? p2:p1; 

    while (p1 || p2) {

    }

    return retp;
}
// @lc code=end

