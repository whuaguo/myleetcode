/*
 * @lc app=leetcode.cn id=300 lang=c
 *
 * [300] 最长递增子序列
 */

// @lc code=start

int lengthOfLIS(int *nums, int numsSize)
{
    int *dp = malloc(sizeof(int) * numsSize);
    assert(dp != NULL);

    int finalMax = 1;

    dp[0] = 1;
    for (int idx = 1; idx < numsSize; idx++)
    {
        int max = 0;
        for (int i = 0; i < idx; i++)
        {
            if ((nums[idx] > nums[i]) && (dp[i] > max))
            {
                max = dp[i];
            }
        }

        dp[idx] = max + 1;
        // printf("dp[%d]: %d\n", idx, dp[idx]);
        if (dp[idx] > finalMax)
        {
            finalMax = dp[idx];
        }
    }

    return finalMax;
}
// @lc code=end
