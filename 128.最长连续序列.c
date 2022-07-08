/*
 * @lc app=leetcode.cn id=128 lang=c
 *
 * [128] 最长连续序列
 */

// @lc code=start

int intCompare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int longestConsecutive(int *nums, int numsSize)
{
    if (numsSize < 2)
    {
        return numsSize;
    }

    qsort(nums, numsSize, sizeof(int), intCompare);

    int max = 1;
    int distance = 1;
    for (int idx = 1; idx < numsSize; idx++)
    {
        if (nums[idx] == nums[idx - 1])
        {
            continue;
        }

        if (nums[idx] == nums[idx - 1] + 1)
        {
            distance++;
            continue;
        }

        if (distance > max)
        {
            max = distance;
        }

        distance = 1;
    }

    return distance > max ? distance : max;
}

// @lc code=end
