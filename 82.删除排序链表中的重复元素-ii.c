/*
 * @lc app=leetcode.cn id=82 lang=c
 *
 * [82] 删除排序链表中的重复元素 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define DUP_WITH_NEXT(ptr) ((ptr->next) && (ptr->val == ptr->next->val))
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *ptr = head;        //当前指针
    struct ListNode *ret = NULL;        //返回的指针
    struct ListNode *prev_ptr = NULL;   //前一个无重复指针

    while (ptr) {
        if (DUP_WITH_NEXT(ptr)) {
            //如果有下一个node, 并且和下一个node值相等

            //循环向下找，直到找到尾部或找到一个node值不一样
            while (DUP_WITH_NEXT(ptr)) {
                ptr = ptr->next;
            }

            //如果前一个无重复指针不为空，直接把他的next指向ptr，删除中间的Node
            if (prev_ptr) {
                prev_ptr->next = ptr->next;
            }
        } else {
            //不一样，如果ret为空，指向当前ptr
            if (ret == NULL) {
                ret = ptr;
            }

            //前一个非重复指针指向ptr
            prev_ptr = ptr;
        }

        //指向那个值不一样的node或尾部NULL
        ptr = ptr->next;
    }

    return ret;
}
// @lc code=end

