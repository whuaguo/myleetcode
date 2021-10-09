/*
 * @lc app=leetcode.cn id=115 lang=c
 *
 * [115] 不同的子序列
 */

// @lc code=start


int numDistinct(char * s, char * t){
    int dp[1001][1001] = {0};
    int slen = strlen(s), tlen = strlen(t);

    for (int i = 0; i <= slen; i++) dp[i][0] = 1;
    for (int i = 1; i <= slen; i++) {
        for (int j = 1; (j <= tlen) && (j <= i); j++) {
            if (s[i - 1] == t[j - 1]) {
                long val = (long)dp[i - 1][j - 1] + (long)dp[i - 1][j];
                dp[i][j] = (val > 0x7fffffff) ? 0: val;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[slen][tlen];
}
// @lc code=end

