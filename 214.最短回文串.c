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

    //复合字符串长度len * 2 + 1, 中间插入特殊字符串“#”。
    //必须添加特殊字符串，否则"aaaa"这样的字符串，正反都一样，合在一起
    //按照KMP字符串算next值的时候，最后一位的值是7，不是我们希望的4
    int tlen = (len << 1) + 1;

    //构造复合字符串，原始字符串+‘#’+翻转字符串
    char *ts = malloc(tlen); 
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

