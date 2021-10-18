/*
 * @lc app=leetcode.cn id=147 lang=c
 *
 * [147] 对链表进行插入排序
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* insertionSortList(struct ListNode* head){
    if (!head || !head->next) {
        return head;
    }

    struct ListNode * ptr_prev = head;
    struct ListNode * ptr = head->next;
    struct ListNode * mptr;
    struct ListNode * mptr_prev;
    while (ptr) {
        int sval = ptr->val;
        if (sval >= ptr_prev->val) {
            //如果不需要移动，就不进行查找
            ptr_prev = ptr;
            ptr = ptr->next;
            continue;
        }

        //开始查找
        mptr = head;
        mptr_prev = NULL;
        while (sval > mptr->val) {
            mptr_prev = mptr;
            mptr = mptr->next;
        }

        //必然找到合适位置
        if (!mptr_prev) {
            head = ptr;
        } else {
            mptr_prev->next = ptr;
        }

        ptr = ptr->next;
        ptr_prev->next->next = mptr;
        ptr_prev->next = ptr;
    }

    return head;
}
// @lc code=end

