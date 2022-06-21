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

    int max = 0;
    int sum = nums[0];

    int left = 0, right = 1;

    while (left < numsSize || right < numsSize)
    {
        while ((right < numsSize) && (nums[right] > 0))
        {
            sum += nums[right];
            right++;
        }

        while ((left < numsSize) && (nums[left] < 0))
        {
            sum -= nums[left];
            left++;
        }

        if (sum > max)
        {
            max = sum;
        }
    }

    return max;
}
// @lc code=end
