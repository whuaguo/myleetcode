/*
 * @lc app=leetcode.cn id=214 lang=c
 *
 * [214] 最短回文串
 */

// @lc code=start


char * shortestPalindrome(char * s){
    int len = strlen(s);
    int tlen = (len << 1) + 1;
    char *ts = malloc(tlen);
    assert(ts);

    memcpy(ts, s, len);
    ts[len] = '+';
    for (int i = 0; i < len ; i++) {
        ts[len + 1 + i] = s[len - 1 - i];
    }

    //total char tlen + 1
    short *next = malloc((tlen + 2)*sizeof(short));
    assert(next);

    int i = 1;
    int j = 0;
    next[1] = 0;
    while (i <= tlen) {
        if ((j == 0) || (ts[i - 1] == ts[j - 1])) {
            next[++i] = ++j;
        } else {
            j = next[j];
        }
    }

    int rn = next[tlen+1] - 1;
    free(next);

    char * ret = malloc(tlen - rn);
    assert(ret);
    
    if (rn < len) {
        memcpy(ret, ts+len+1, len - rn);
    }
    memcpy(ret + len -rn, s, len + 1);

    free(ts);
    return ret;
}
// @lc code=end

