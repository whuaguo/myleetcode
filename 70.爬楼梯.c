/*
 * @lc app=leetcode.cn id=70 lang=c
 *
 * [70] 爬楼梯
 */

// @lc code=start

int climbStairs(int n)
{
    if (n == 1)
    {
        return 1;
    }
    int *steps = malloc(sizeof(int) * n);
    assert(steps);

    steps[0] = 1;
    steps[1] = 2;
    for (int idx = 2; idx < n; idx++)
    {
        steps[idx] = steps[idx - 1] + steps[idx - 2];
    }

    return steps[n - 1];
}
// @lc code=end
