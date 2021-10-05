/*
 * @lc app=leetcode.cn id=86 lang=c
 *
 * [86] 分隔链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode *ret = NULL;
    struct ListNode *ptr = head;
    struct ListNode *tail = NULL;
    struct ListNode *prev = NULL;
    struct ListNode *buffer_ptr;

    while (ptr) {
        buffer_ptr = ptr;
        ptr = ptr->next;

        //小于x，移动到tail后面
        if (buffer_ptr->val < x) {
            if (ret == NULL) {
                ret = buffer_ptr;
            } 

            if (prev) {            
                prev->next = buffer_ptr->next;
                
                if (tail) {
                    buffer_ptr->next = tail->next;
                    tail->next = buffer_ptr;
                } else {
                    buffer_ptr->next = head;
                }
            }

            tail = buffer_ptr;
        } else {
            prev = buffer_ptr;
        }
    }

    return ret ? ret : head;
}
// @lc code=end

