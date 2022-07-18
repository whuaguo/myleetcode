/*
 * @lc app=leetcode.cn id=237 lang=c
 *
 * [237] 删除链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode *node)
{
    struct ListNode *next = node->next;
    assert(next);

    node->val = next->val;
    node->next = next->next;
    free(next);
}
// @lc code=end
