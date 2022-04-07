/*
 * @lc app=leetcode.cn id=315 lang=c
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define log printf
#if 0
int findIdxInSortNums(int *nums, int *numsSize, int value)
{
    /*
    log("Sort numbers (%d) is [", *numsSize);
    for (int idx = 0; idx < *numsSize; idx++)
    {
        log("%d,", nums[idx]);
    }
    log("].\nNew number is %d\n", value);
    */

    int left = 0;
    int right = *numsSize - 1;
    int ret;

    if (nums[right] < value)
    {
        nums[*numsSize] = value;
        *numsSize += 1;
        return right + 1;
    }

    if (nums[left] >= value)
    {
        ret = 0;
    }
    else
    {
        int mid;
        while (left <= right)
        {
            mid = (left + right) >> 1;

            if (value > nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        ret = left;
    }

    while (nums[left] == value)
    {
        left++;
    }

    for (int idx = *numsSize; idx > left; idx--)
    {
        nums[idx] = nums[idx - 1];
    }
    nums[left] = value;
    *numsSize += 1;

    return ret;
}
#endif
int intCompare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int *countSmaller(int *nums, int numsSize, int *returnSize)
{
    int *ret = malloc(sizeof(int) * numsSize);
    assert(ret != NULL);
    *returnSize = numsSize;

    int *sortnums = malloc(sizeof(int) * numsSize);
    assert(sortnums != NULL);
    int sortnumsSize = numsSize;

    /*
    int sortnumsSize = 1;
    ret[numsSize - 1] = 0;
    sortnums[0] = nums[numsSize - 1];

    for (int idx = numsSize - 2; idx >= 0; idx--)
    {
        int index = findIdxInSortNums(sortnums, &sortnumsSize, nums[idx]);
        ret[idx] = index;
    }
    */

    memcpy(sortnums, nums, sizeof(int) * numsSize);
    qsort(sortnums, numsSize, sizeof(int), intCompare);

    int i = 1;
    int j = 1;
    while (j < numsSize)
    {
        if (sortnums[j] != sortnums[i - 1])
        {
            if (i != j)
            {
                sortnums[i] = sortnums[j];
            }
            j++;
            i++;
        }
        else
        {
            j++;
        }
    }
    sortnumsSize = i;

    /*
    log("The sort nums(%d) are [", sortnumsSize);
    for (int idx = 0; idx < sortnumsSize; idx++)
    {
        log("%d,", sortnums[idx]);
    }
    log("]\n");
    */
    int *sortCounts = malloc(sizeof(int) * sortnumsSize);
    assert(sortCounts != NULL);
    memset(sortCounts, 0, sizeof(int) * sortnumsSize);

    for (int idx = numsSize - 1; idx >= 0; idx--)
    {
        int *sortNumber = (int *)bsearch(&nums[idx], sortnums, sortnumsSize, sizeof(int), intCompare);
        int sortIdx = sortNumber - sortnums;

        for (int i = sortIdx; i < sortnumsSize; i++)
        {
            sortCounts[i]++;
        }

        ret[idx] = sortIdx ? sortCounts[sortIdx - 1] : 0;
    }

    return ret;
}
// @lc code=end
