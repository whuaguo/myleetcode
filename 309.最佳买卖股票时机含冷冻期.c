/*
 * @lc app=leetcode.cn id=309 lang=c
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
#define delta(idx, i) (prices[idx] - prices[i])
#define prev(idx) ((idx < 3) ? 0 : (dp[idx - 2]))

int maxProfit(int *prices, int pricesSize)
{
    int *dp = malloc(sizeof(int) * pricesSize);
    dp[0] = 0;
    for (int idx = 1; idx < pricesSize; idx++)
    {
        int max = 0;
        for (int i = 0; i < idx; i++)
        {
            int value = (prices[i] < prices[idx])
                            ? delta(idx, i) + prev(i)
                            : dp[i];

            if (max < value)
            {
                max = value;
            }
        }
        dp[idx] = max;
    }

    return dp[pricesSize - 1];
}
// @lc code=end
