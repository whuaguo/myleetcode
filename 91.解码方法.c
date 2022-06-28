/*
 * @lc app=leetcode.cn id=91 lang=c
 *
 * [91] 解码方法
 */

// @lc code=start

int numDecodings(char *s)
{
    int len = strlen(s) + 1;
    int *dp = malloc(len * sizeof(int));
    assert(dp != NULL);

    dp[0] = 1;
    for (int idx = 1; idx < len; idx++)
    {
        if (s[idx - 1] == '0')
        {
            //当前是0
            if ((idx > 1) &&
                (s[idx - 2] == '1' || s[idx - 2] == '2'))
            {
                //必须前一位非0，并且是1或2
                dp[idx] = dp[idx - 2];
            }
            else
            {
                //不可能情况，‘00’，‘30’...
                return 0;
            }
        }
        else
        {
            //最后一位单独情况
            dp[idx] = dp[idx - 1];

            //判断是否可能最后两位一种情况
            if ((idx > 1) &&
                ((s[idx - 2] == '1') || (s[idx - 2] == '2' && s[idx - 1] < '7')))
            {
                dp[idx] += dp[idx - 2];
            }
        }
    }

    return dp[len - 1];
}
// @lc code=end
