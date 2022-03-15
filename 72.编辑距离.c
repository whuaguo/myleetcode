/*
 * @lc app=leetcode.cn id=72 lang=c
 *
 * [72] 编辑距离
 */

// @lc code=start


int minDistance(char * word1, char * word2){
    while ((*word1!= '\0') && (*word1 == *word2)) {
        if (*word2 == '\0') {
            break;
        }
        word1++;
        word2++;
    }
    
#if 0
    char *w1 = word1 + strlen(word1) - 1;
    char *w2 = word2 + strlen(word2) - 1;

    while ((w1>=word1)&&(w2>=word2) && (*w1 == *w2)) {
        w1--;
        w2--;
    }

    *(w1 + 1) = '\0';
    *(w2 + 1) = '\0';
#endif
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    if (!len1 || !len2) return len1+len2;

    int dp[501][501] = {0};

    for (int idx = 0; idx < len2; idx ++) {
        dp[0][idx+1] = idx + 1;
    }

    for (int idx = 0; idx < len1; idx ++) {
        dp[idx+1][0] = idx + 1;
    }

    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (word1[i] == word2[j]) {
                dp[i+1][j+1] = dp[i][j];
            } else {
                int min = dp[i][j];
                if (dp[i+1][j] < min) {
                    min = dp[i+1][j];
                }
                if (dp[i][j+1] < min) {
                    min = dp[i][j+1];
                }
                dp[i+1][j+1] = min+1;
            }
        }
    }
    return dp[len1][len2];
}
// @lc code=end

