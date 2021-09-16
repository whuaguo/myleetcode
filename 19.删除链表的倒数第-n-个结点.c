/*
 * @lc app=leetcode.cn id=19 lang=c
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *ptr = head;
    struct ListNode *later_ptr = head;
    int num = n;

    if (n==0) {
        return head;
    }

    while (ptr && (num > 0)) {
        num --;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        if (num==0) {
            head = head->next;
            return head;
        } else {
            return head;
        }
    }

    while (ptr->next) {
        ptr = ptr->next;
        later_ptr = later_ptr->next;
    }

    if (later_ptr->next) {
        later_ptr->next = later_ptr->next->next;
    }
    
    return head;
}
// @lc code=end

