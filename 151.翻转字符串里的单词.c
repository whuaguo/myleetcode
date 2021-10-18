/*
 * @lc app=leetcode.cn id=151 lang=c
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
char * reverseWords(char * s){
    char buffer[10000] = {0};
    int newstrlen = 0;
    int len = strlen(s);
    int to = 0;
    int from = 0;
    bool new = false;

    for (int idx = len - 1; idx >= 0; idx --) {
        if (s[idx] != ' ') {
            if (!new) {
                new = true;
                to = idx;
            }
            from = idx;
        } else {
            if (new) {
                int cplen = to - from + 1;
                if (newstrlen) {
                    buffer[newstrlen++] = ' ';
                }

                memcpy(buffer + newstrlen, s + from, cplen);
                newstrlen += cplen ;
                new = false;
            }
        }
    }

    if (new) {
        int cplen = to - from + 1;
        if (newstrlen) {
            buffer[newstrlen++] = ' ';
        }

        memcpy(buffer + newstrlen, s + from, cplen);
        newstrlen += cplen ;
    }

    memcpy(s, buffer, newstrlen);
    s[newstrlen] = 0;
    
    return s;
}
// @lc code=end

