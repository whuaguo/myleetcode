/*
 * @lc app=leetcode.cn id=53 lang=c
 *
 * [53] 最大子数组和
 */

// @lc code=start
int maxSubArray(int *nums, int numsSize)
{
    if (!numsSize)
        return 0;

    int max = nums[0];
    int sum = max;
    int right = 1;

    while (right < numsSize)
    {
        if (sum < 0)
        {
            sum = nums[right++];
        }
        else
        {
            sum += nums[right++];
        }

        if (sum > max)
        {
            max = sum;
        }
    }

    return max;
}

// @lc code=end
