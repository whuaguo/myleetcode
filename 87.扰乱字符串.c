/*
 * @lc app=leetcode.cn id=87 lang=c
 *
 * [87] 扰乱字符串
 */

// @lc code=start

bool isScramble(char *s1, char *s2)
{
    if (!strcmp(s1, s2))
        return true;

    int n = strlen(s1);
    bool f[40][40][40] = {false};

    // 先处理长度为 1 的情况
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            f[i][j][1] = (s1[i] == s2[j]);
        }
    }

    // 再处理其余长度情况
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i + len <= n; i++)
        {
            for (int j = 0; j + len <= n; j++)
            {
                for (int k = 1; (k < len) && !f[i][j][len]; k++)
                {
                    bool a = f[i][j][k] && f[i + k][j + k][len - k];
                    bool b = f[i][j + len - k][k] && f[i + k][j][len - k];

                    if (a || b)
                        f[i][j][len] = true;
                }
            }
        }
    }
    return f[0][0][n];
}
// @lc code=end
