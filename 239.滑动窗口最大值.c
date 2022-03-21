/*
 * @lc app=leetcode.cn id=239 lang=c
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//#define log
#define log printf

void logCaches(int *caches, int k)
{
    log("The caches (%d) are [", k);
    for (int idx = 0; idx < k; idx++)
    {
        log("%d,", caches[idx]);
    }
    log("]\n");
}

int *maxSlidingWindow(int *nums, int numsSize, int k, int *returnSize)
{
    int *caches = malloc(sizeof(int) * k);
    int *ret = malloc(sizeof(int) * (numsSize - k + 1));
    assert(caches != NULL);
    assert(ret != NULL);

    *returnSize = numsSize - k + 1;
    return ret;
}
// @lc code=end
