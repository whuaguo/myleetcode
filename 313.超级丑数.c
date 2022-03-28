/*
 * @lc app=leetcode.cn id=313 lang=c
 *
 * [313] 超级丑数
 */

// @lc code=start
#define log printf
int nthSuperUglyNumber(int n, int *primes, int primesSize)
{
    int *dp = malloc(sizeof(int) * (n + 1));
    int *index = malloc(sizeof(int) * primesSize);
    long *nums = malloc(sizeof(long) * primesSize);
    assert(dp != NULL);
    assert(index != NULL);
    assert(nums != NULL);

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 0; i < primesSize; i++)
    {
        index[i] = 1;
        nums[i] = primes[i];
    }

    for (int i = 2; i <= n;)
    {
        int newValueIndex;
        int minNumber = 0x7FFFFFFF;
        for (int j = 0; j < primesSize; j++)
        {
            if (nums[j] < minNumber)
            {
                newValueIndex = j;
                minNumber = nums[j];
            }
        }

        if (minNumber != dp[i - 1])
        {
            dp[i] = minNumber;
            i++;
        }

        index[newValueIndex] += 1;
        nums[newValueIndex] = (long)primes[newValueIndex] * dp[index[newValueIndex]];
    }

    return dp[n];
}
// @lc code=end
