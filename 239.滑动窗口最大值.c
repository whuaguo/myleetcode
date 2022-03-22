/*
 * @lc app=leetcode.cn id=239 lang=c
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//#define DEBUG 1
//#define HEAP    1
#define QUEUE 1

#if (defined QUEUE)
int *gnums;

#ifdef DEBUG
#define log printf
void logqueue(int *queue, int qsize)
{
    log("The queue (%d) are [", qsize);
    for (int idx = 0; idx < qsize; idx++)
    {
        log("%d[%d],", queue[idx], gnums[queue[idx]]);
    }
    log("]\n");
}
#else
#define log
#define logqueue
#endif

int idxqCompare(const void *a, const void *b)
{
    return (gnums[*(int *)b] - gnums[*(int *)a]);
}

void idxqAdd(int *queue, int *qsize, int gnumidx)
{
    int mid;
    int left = 0;
    int right = *qsize - 1;

    while (left <= right)
    {
        mid = (left + right) >> 1;

        if (gnums[queue[mid]] > gnums[gnumidx])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    queue[left] = gnumidx;
    *qsize = left + 1;
}
#endif

#if (defined HEAP)
#ifdef DEBUG
#define log printf
void logHeap(int *heap, int heapSize)
{
    log("The heap (%d) are [", heapSize);
    for (int idx = 0; idx < heapSize; idx++)
    {
        log("%d,", heap[idx]);
    }
    log("]\n");
}
#else
#define log
#define logHeap
#endif

#define father(idx) ((idx - 1) >> 1)
#define lchild(idx) ((idx << 1) + 1)
#define rchild(idx) ((idx << 1) + 1)

#define swap(idx, nidx, heapSize)             \
    {                                         \
        cidx[heapidx[idx] % heapSize] = nidx; \
        cidx[heapidx[nidx] % heapSize] = idx; \
        int temp = heapidx[nidx];             \
        heapidx[nidx] = heapidx[idx];         \
        heapidx[idx] = temp;                  \
        idx = nidx;                           \
    }

void moveHeapNode(int *nums, int *heapidx, int *cidx, int heapSize, int idx)
{
    // log("Move %dth Node(%d)\n", idx, nums[heapidx[idx]]);
    if (!idx)
        goto movedown;

    int fidx = father(idx);
    if (nums[heapidx[idx]] > nums[heapidx[fidx]])
        goto moveup;

    int nidx;
    int lidx;
    int ridx;

movedown:
    while (idx < (heapSize >> 1))
    {
        lidx = lchild(idx);
        ridx = lidx + 1;
        nidx = ((ridx < heapSize) && (nums[heapidx[ridx]] > nums[heapidx[lidx]])) ? ridx : lidx;

        if (nums[heapidx[idx]] < nums[heapidx[nidx]])
        {
            swap(idx, nidx, heapSize);
        }
        else
        {
            return;
        }
    }
    return;

moveup:
    while (idx && (nums[heapidx[idx]] > nums[heapidx[fidx]]))
    {
        swap(idx, fidx, heapSize);
        fidx = father(idx);
    }

    return;
}
#endif

int *maxSlidingWindow(int *nums, int numsSize, int k, int *returnSize)
{
#if (defined QUEUE)
    int *qidx = malloc(sizeof(int) * numsSize);
    int *ret = malloc(sizeof(int) * (numsSize - k + 1));
    assert(qidx != NULL);
    assert(ret != NULL);

    int qsize = k;
    gnums = nums;
    for (int idx = 0; idx < k; idx++)
    {
        qidx[idx] = idx;
    }
    qsort(qidx, qsize, sizeof(int), idxqCompare);
    // logqueue(qidx, qsize);

    ret[0] = nums[qidx[0]];
    // log("The %dth result is %d\n", 0, nums[qidx[0]]);
    for (int idx = k; idx < numsSize; idx++)
    {
        idxqAdd(qidx, &qsize, idx);

        while (qidx[0] <= idx - k)
        {
            qidx++;
            qsize--;
        }
        // logqueue(qidx, qsize);
        // log("The %dth result is %d\n", idx - k + 1, nums[qidx[0]]);
        ret[idx - k + 1] = nums[qidx[0]];
    }

    free(qidx);
    *returnSize = numsSize - k + 1;
    return ret;
#endif
#if (defined HEAP)
    int *heapidx = malloc(sizeof(int) * k);
    int *cidx = malloc(sizeof(int) * k);
    int *ret = malloc(sizeof(int) * (numsSize - k + 1));
    assert(heapidx != NULL);
    assert(cidx != NULL);
    assert(ret != NULL);

    heapidx[0] = 0;
    cidx[0] = 0;
    for (int idx = 1; idx < k; idx++)
    {
        heapidx[idx] = idx;
        cidx[idx] = idx;
        moveHeapNode(nums, heapidx, cidx, idx + 1, idx);
    }

    // logHeap(heapidx, k);
    // log("RET[0]:%d\n", nums[heapidx[0]]);
    ret[0] = nums[heapidx[0]];

    int hidx = 0;
    int ridx = 1;
    for (int idx = k; idx < numsSize; idx++)
    {
        // log("Replace %d with %d\n", nums[heapidx[cidx[hidx]]], nums[idx]);
        heapidx[cidx[hidx]] = idx;
        moveHeapNode(nums, heapidx, cidx, k, cidx[hidx++]);

        // logHeap(heapidx, k);
        // log("RET[%d]:%d\n", ridx, nums[heapidx[0]]);
        ret[ridx++] = nums[heapidx[0]];
        if (hidx == k)
        {
            hidx = 0;
        }
    }

    free(heapidx);
    free(cidx);
    *returnSize = ridx;
    return ret;
#endif
}

// @lc code=end
