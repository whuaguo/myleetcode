/*
 * @lc app=leetcode.cn id=53 lang=c
 *
 * [53] 最大子数组和
 */

// @lc code=start
int maxSubArray(int *nums, int numsSize)
{
    int max = 0x80000000;
    int sum = 0;

    for (int right = 0; right < numsSize; right++)
    {
        sum += nums[right];
        if (sum > max)
        {
            max = sum;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }

    return max;
}

// @lc code=end
