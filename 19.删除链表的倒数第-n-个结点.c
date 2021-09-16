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

    //check if n is valid
    if (n <= 0) {
        return head;
    }

    //try to go n steps firstly
    while (ptr && (num > 0)) {
        num --;
        ptr = ptr->next;
    }

    //already reach end
    if (ptr == NULL) {
        if (num == 0) {
            //also finish n steps, remove the head
            head = head->next;
            return head;
        } else {
            //can not finish n steps, just do nothing and return
            return head;
        }
    }

    //let ptr go to the end, and the later_ptr's next node will be removed.
    while (ptr->next) {
        ptr = ptr->next;
        later_ptr = later_ptr->next;
    }

    //remove the node
    if (later_ptr->next) {
        later_ptr->next = later_ptr->next->next;
    }
    
    return head;
}
// @lc code=end

