/*
 * @lc app=leetcode.cn id=230 lang=c
 *
 * [230] 二叉搜索树中第K小的元素
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define log printf

#define father(idx) ((idx - 1) >> 1)
#define lchild(idx) ((idx << 1) + 1)
#define rchild(idx) ((idx << 1) + 1)

#define swap(idx, nidx)         \
    {                           \
        int temp = heap[nidx];  \
        heap[nidx] = heap[idx]; \
        heap[idx] = temp;       \
        idx = nidx;             \
    }

void heapMove(int *heap, int heapSize, int idx)
{
    if (!idx)
    {
        int lidx, ridx, nidx;
        while (idx < (heapSize >> 1))
        {
            lidx = lchild(idx);
            ridx = lidx + 1;
            nidx = ((ridx < heapSize) && (heap[ridx] > heap[lidx])) ? ridx : lidx;

            if (heap[idx] < heap[nidx])
            {
                swap(idx, nidx);
            }
            else
            {
                return;
            }
        }
    }
    else
    {
        int fidx = father(idx);
        while (idx && (heap[idx] > heap[fidx]))
        {
            swap(idx, fidx);
            fidx = father(idx);
        }
    }
}

void heapChange(int *heap, int *heapSize, int heapSizeMax, int newValue)
{
    log("Visit %d\n", newValue);

    if (*heapSize < heapSizeMax)
    {
        heap[*heapSize] = newValue;
        *heapSize += 1;
        heapMove(heap, *heapSize, *heapSize - 1);
    }
    else if (heap[0] > newValue)
    {
        heap[0] = newValue;
        heapMove(heap, *heapSize, 0);
    }
}

int kthSmallest(struct TreeNode *root, int k)
{
    int heap[k];
    struct TreeNode *stack[100];
    int heapSize = 0;
    int stackSize = 0;
    struct TreeNode *pNode = root;

    while (stackSize || pNode)
    {
        while (!pNode && stackSize)
        {
            pNode = stack[stackSize - 1];
            stackSize--;
            heapChange(heap, &heapSize, k, pNode->val);
            pNode = pNode->right;
        }

        if (pNode)
        {
            while (pNode->left)
            {
                stack[stackSize++] = pNode;
                pNode = pNode->left;
            }

            heapChange(heap, &heapSize, k, pNode->val);
            pNode = pNode->right;
        }
    }

    return heap[0];
}
// @lc code=end
