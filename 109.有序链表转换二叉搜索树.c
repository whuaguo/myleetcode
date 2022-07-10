/*
 * @lc app=leetcode.cn id=109 lang=c
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *sortedListsToBST(struct ListNode *head, struct ListNode *tail)
{
    struct ListNode *pmid = head;
    struct ListNode *ptail = head;

    while (ptail != tail)
    {
        ptail = ptail->next;
        if (ptail == tail)
        {
            break;
        }

        ptail = ptail->next;
        pmid = pmid->next;
    }

    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    assert(root != NULL);

    root->val = pmid->val;
    root->left = (pmid == head) ? NULL : sortedListsToBST(head, pmid);
    root->right = (pmid->next == tail) ? NULL : sortedListsToBST(pmid->next, tail);
    return root;
}

struct TreeNode *sortedListToBST(struct ListNode *head)
{
    if (!head)
    {
        return NULL;
    }

    return sortedListsToBST(head, NULL);
}
// @lc code=end

