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
    int total = nums[0];
    int sum = total;

    int left = 1, right = 1;

    while (left < numsSize || right < numsSize)
    {
        while (nums[right] > 0)
        {
            sum += nums[right];
            right++;
        }

        total = sum;
        if (total > max)
        {
            max = total;
        }

        while (nums[left] < 0)
        {
            total -= nums[left];
            left++;
        }

        if (total > max)
        {
            max = total;
        }
    }

    return max;
}
// @lc code=end
