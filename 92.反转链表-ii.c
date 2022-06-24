/*
 * @lc app=leetcode.cn id=92 lang=c
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *reverseBetween(struct ListNode *head, int left, int right)
{
    //只有一个节点，不用干任何事情
    if (left == right)
    {
        return head;
    }

    struct ListNode *pPrev = NULL;
    struct ListNode *pTail;

    //找到left对应的节点，pTail指向需要反转链表的尾部， pPrev指向反转链表前一个节点
    if (left == 1)
    {
        pTail = head;
    }
    else
    {
        pPrev = head;

        for (int idx = 1; idx < left - 1; idx++)
        {
            pPrev = pPrev->next;
        }
        pTail = pPrev->next;
    }

    struct ListNode *pOldHead;
    struct ListNode *pHead = pTail;
    struct ListNode *pNextHead = pHead->next;

    //开始反转子链表，pHead指向需要反转链表的头部，pNextHead指向子链表的下一个节点
    for (int idx = left; idx < right; idx++)
    {
        pOldHead = pHead;            //保存老的头部节点
        pHead = pNextHead;           //头部节点下移
        pNextHead = pNextHead->next; //下一个几点也下移
        pHead->next = pOldHead;      //新节点加入反转子链表
    }

    //反转尾部节点指向下一个节点
    pTail->next = pNextHead;

    //反转子链表前一个节点指向反转子链表
    if (pPrev)
    {
        pPrev->next = pHead;
        return head;
    }

    return pHead;
}
// @lc code=end
