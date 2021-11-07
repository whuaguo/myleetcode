/*
 * @lc app=leetcode.cn id=214 lang=c
 *
 * [214] 最短回文串
 */

// @lc code=start

/*
 * 使用KMP算法
 * 把String翻转，附加到string尾部，用特殊符号+分开
 * 开头的回文字符子串会在整个字符串尾部，用KMP算法计算next，
 * 尾部的next值就是头部回文字符串长度，截取反转字符串+源字符串尾部即可
 */
char * shortestPalindrome(char * s){
    int len = strlen(s);
    int tlen = len << 1;
    char *ts = malloc(tlen + 1);
    assert(ts);

    memcpy(ts, s, len);
    /*
     * Must insert a special char between orignal string and the reversed string,
     * otherwise, the next value may be bigger than the length of the string
     * for example, string = "aaaaa", string + reversed string = "aaaaaaaaaa",
     * the last next value will be 9, but we should get 5
     */
    ts[len] = '+'; 
    
    for (int i = 0; i < len ; i++) {
        ts[len + 1 + i] = s[len - 1 - i];
    }

    //total char tlen + 1
    short *next = malloc((tlen + 3)*sizeof(short));
    assert(next);

    int i = 1;
    int j = 0;
    next[1] = 0;
    while (i <= tlen+1) {
        if ((j == 0) || (ts[i - 1] == ts[j - 1])) {
            next[++i] = ++j;
        } else {
            j = next[j];
        }
    }

    int rn = next[tlen+2] - 1;
    free(next);

    char * ret = malloc(tlen - rn + 1);
    assert(ret);
    
    if (rn < len) {
        memcpy(ret, ts+len+1, len - rn);
    }
    memcpy(ret + len -rn, s, len + 1);

    free(ts);
    return ret;
}
// @lc code=end

