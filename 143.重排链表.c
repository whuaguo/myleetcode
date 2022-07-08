/*
 * @lc app=leetcode.cn id=143 lang=c
 *
 * [143] 重排链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#ifdef DEBUG
void printList(struct ListNode *head)
{
    struct ListNode *node = head;

    printf("The values of the list is:[");
    while (head)
    {
        printf("%d,", head->val);
        head = head->next;
    }
    printf("]\n");
}
#endif

void reorderList(struct ListNode *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    //找到中间节点的前一个节点。
    struct ListNode *pmid = NULL;
    struct ListNode *ptail = head;
    while (ptail)
    {
        ptail = ptail->next;
        if (ptail)
        {
            ptail = ptail->next;
            pmid = pmid ? pmid->next : head;
        }
    }

    //截断
    ptail = pmid;
    pmid = pmid->next;
    ptail->next = NULL;

    //把后半段翻转
    ptail = pmid;
    struct ListNode *head2 = NULL;
    while (ptail)
    {
        pmid = ptail->next;
        ptail->next = head2;
        head2 = ptail;
        ptail = pmid;
    }

    //把两段ptail,head2间隔交叉
    ptail = head;
    while (ptail)
    {
        pmid = ptail->next;  //缓存头1的下个节点
        ptail->next = head2; //头一指向头二
        head2 = head2->next; //头二下移
        if (pmid)
        {
            ptail->next->next = pmid; //老的头二指向新的头一
        }
        ptail = pmid; //头一下移
    }

    return head;
}
// @lc code=end
