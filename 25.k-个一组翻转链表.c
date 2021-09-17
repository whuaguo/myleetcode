/*
 * @lc app=leetcode.cn id=25 lang=c
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode *phead = NULL;
    struct ListNode *ptail = NULL;
    struct ListNode *p1 = head;
    struct ListNode *p2 = head;
    int steps;

    if ((head == NULL) || (head->next == NULL) || (k==1)) {
        return head;
    }

    while (p2) {
        steps = k - 1;

        while ((steps > 0) && p2) {
            steps --;
            p2 = p2->next;
        }

        //不够k，直接跳出
        if (!p2) {
            break;
        }

        //设置head
        if (phead == NULL) {
            phead = p2;
        }

        //设置尾部链接
        if (ptail) {
            ptail->next = p2;
        }
        //新尾部
        ptail = p1;

        //翻转区域链表 
        struct ListNode *ptr = p1;
        struct ListNode *ptr1 = p2->next;
        while (ptr != p2) {
            ptr = ptr->next;
            p1->next = ptr1;
            ptr1 = p1;
            p1 = ptr;
        }

        //为下一轮设置p1/p2
        p1 = p2->next;
        p2->next = ptr1;
        p2 = p1;
    }

    return phead ? phead : head;
}
// @lc code=end

