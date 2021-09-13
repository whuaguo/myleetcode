/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* n1 = l1;
    struct ListNode* n2 = l2;
    struct ListNode* num_head = NULL;
    struct ListNode* prenum;
    struct ListNode* retp = NULL;
    int more = 0;

    while (n1 || n2 || more)
    {
        int num;
        prenum = retp;
        retp = (struct ListNode *) malloc(sizeof(*l1));
        if (!retp) {
            return NULL;
        }

        if (prenum)  {
            prenum->next = retp;
        }
        
        //if retnum is NULL, this is the header
        if (!num_head) {
            num_head = retp;
        }        

        num = (n1?(n1->val):0) + (n2?(n2->val):0) + more;
        if (num >=10) {
            retp->val = num - 10;
            more = 1;
        } else {
            retp->val = num;
            more = 0;
        }

        if (n1) {
            n1 = n1->next;
        }
        if (n2) {
            n2 = n2->next;
        }
    }

    if (retp) {
        retp->next = NULL;
    }
    
    return num_head;    
}
// @lc code=end

