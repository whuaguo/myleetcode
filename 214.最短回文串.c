/*
 * @lc app=leetcode.cn id=214 lang=c
 *
 * [214] 最短回文串
 */

// @lc code=start


char * shortestPalindrome(char * s){
    int len = strlen(s);

    //复合字符串长度len * 2 + 1, 中间插入特殊字符串“#”。
    //必须添加特殊字符串，否则"aaaa"这样的字符串，正反都一样，合在一起
    //按照KMP字符串算next值的时候，最后一位的值是7，不是我们希望的4
    int tlen = (len << 1) + 1;

    //构造复合字符串，原始字符串+‘#’+翻转字符串
    char *ts = malloc(tlen); 
    assert(ts);
    memcpy(ts, s, len);
    ts[len] = '#';
    for (int i = 0; i < len ; i++) {
        ts[len + 1 + i] = s[len - 1 - i];
    }

    //next数组的长度是，n+2，下标x计算前面x-1个字符的next值，长度为n
    //的字符串，最后一个next值的下标是n+1，那么数组的长度就是n+2
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

