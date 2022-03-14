/*
 * @lc app=leetcode.cn id=10 lang=c
 *
 * [10] 正则表达式匹配
 */

// @lc code=start


bool isMatch(char * s, char * p){
    bool dp[31][31] = {0};

    dp[0][0] = true;

    int slen = strlen(s);
    int plen = strlen(p);
    dp[0][0] = true;  //dp[i+1][j+1] 表示前i，j可匹配

    for (int i = 0; i < slen; i++) {
        dp[i + 1][0] = false;
    }

    for (int j = 0; j < plen; j++) {
        if (p[j] != '*') {
            dp[0][j + 1] = false;
        } else {
            dp[0][j + 1] = dp[0][j - 1];
        }
    }

    for (int i = 0; i < slen; i++) {
        for (int j = 0; j < plen; j++) {
            if ((p[j] == '.')) {
                //如果p[j] == '.' 那么dp[i+1][j+1] = dp[i][j]
                dp[i+1][j+1] = dp[i][j];
            } else if (p[j] == '*'){
                int idx = i;
                //通配符匹配0个字符，是否匹配看前(i,j-2)是否匹配
                dp[i+1][j+1] = dp[i+1][j-1];

                //如果不匹配，尝试*+前一个字符匹配一个或多个，
                //如果结果匹配了，或字符不相等退出匹配尝试
                while (!dp[i+1][j+1] && (idx >= 0)){
                    if ((s[idx] == p[j - 1]) || (p[j-1]=='.')) {
                        dp[i+1][j+1] = dp[idx--][j-1];
                    } else {
                        break;
                    }
                }
            } else {
                //不是通配符，如果尾部相等，  那么是否匹配看尾部前面是否匹配
                //           如果尾部不相等，肯定不匹配
                dp[i+1][j+1] = ((s[i] == p[j])? dp[i][j] : false);
            }
        }
    }

    return dp[slen][plen];
}
// @lc code=end

