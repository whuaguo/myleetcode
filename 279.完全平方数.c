/*
 * @lc app=leetcode.cn id=279 lang=c
 *
 * [279] 完全平方数
 */

// @lc code=start

//测试例会反复调用，使用全局变量防止重复计算
int dp[10001] = {0};
int dpmin = 1;

int numSquares(int n)
{
    //如果全局变量没有初始化过，先把完全平方数计算出来
    if (!dp[1])
    {
        for (int i = 1; i <= 100; i++)
        {
            dp[i * i] = 1;
        }
    }

    //已经计算过，直接返回
    if (dp[n])
    {
        return dp[n];
    }

    //动态规划一次求解
    for (int i = dpmin + 1; i <= n; i++)
    {
        if (dp[i])
        {
            continue;
        }

        int min = i;
        for (int j = 1; j <= (i >> 1); j++)
        {
            if (dp[j] != 1)
            {
                continue;
            }

            int dpij = 1 + dp[i - j];
            if (dpij < min)
            {
                min = dpij;
            }
        }

        dp[i] = min;
    }

    dpmin = n;
    return dp[n];
}
// @lc code=end
