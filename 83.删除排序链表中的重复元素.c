/*
 * @lc app=leetcode.cn id=83 lang=c
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *ptr = head;        //当前指针
    struct ListNode *prev_ptr = NULL;   //前一个无重复指针

    while (ptr) {
        //循环向下找，直到找到尾部或找到一个node值不一样
        while (ptr->next && (ptr->val == ptr->next->val)) {
            ptr = ptr->next;
        }

        //如果前一个无重复指针不为空，直接把他的next指向ptr，删除中间的Node
        if (prev_ptr) {
            prev_ptr->next = ptr;
        } else {
            head = ptr;
        } 

        prev_ptr = ptr;

        //取下一个指针
        ptr = ptr->next;
    }

    return head;
}
// @lc code=end

