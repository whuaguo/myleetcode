/*
 * @lc app=leetcode.cn id=61 lang=c
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *rotateRight(struct ListNode *head, int k)
{
    struct ListNode *tail = head;
    struct ListNode *newHead = head;

    int move = k;

    while (newHead->next && (move--))
    {
        newHead = newHead->next;
    }

    return newHead;
}
// @lc code=end
