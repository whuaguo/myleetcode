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

int *countSmaller(int *nums, int numsSize, int *returnSize)
{
    int *ret = malloc(sizeof(int) * numsSize);
    assert(ret != NULL);
    *returnSize = numsSize;

    int *sortnums = malloc(sizeof(int) * numsSize);
    assert(sortnums != NULL);
    int sortnumsSize = 1;

    ret[numsSize - 1] = 0;
    sortnums[0] = nums[numsSize - 1];

    for (int idx = numsSize - 2; idx >= 0; idx--)
    {
        int index = findIdxInSortNums(sortnums, &sortnumsSize, nums[idx]);
        ret[idx] = index;
    }

    return ret;
}
// @lc code=end
