/*
 * @lc app=leetcode.cn id=160 lang=c
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (!headA || !headB) {
        return NULL;
    }
    struct ListNode * p1 = headA;
    struct ListNode * p2 = headB;
    while (p1 != p2) { // 若是有缘，你们早晚会相遇
        p1 = p1 ? p1->next : headB; // 当你走到终点时，开始走她走过的路
        p2 = p2 ? p2->next : headA; // 当她走到终点时，开始走你走过的路
    }

    //要么相聚在交点，要么一起走到NULL
    return p1;
}
// @lc code=end

