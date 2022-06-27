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
    if (!head)
    {
        return head;
    }

    struct ListNode *tail = head;
    int lk = k;
    int len = 0;

retry:
    //先向前移动，要么K步，要么到尾部
    while (tail->next && lk)
    {
        tail = tail->next;
        len++;
        lk--;
    }

    if (lk)
    {
        //先移动到尾部，说明k比链表len大，重新计算真正需要移动的步数
        tail = head;
        lk = k % ++len;

        if (!lk)
        {
            //不需要移动，直接返回
            return head;
        }
        else
        {
            //需要移动，重新开始
            goto retry;
        }
    }

    //快慢指针开始同步移动
    struct ListNode *newTail = head;
    while (tail->next)
    {
        tail = tail->next;
        newTail = newTail->next;
    }

    tail->next = head;    //尾部连接头部
    head = newTail->next; //新的头部
    newTail->next = NULL; //新的尾部指向NULL

    return head;
}
// @lc code=end
