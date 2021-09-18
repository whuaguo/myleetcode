/*
 * @lc app=leetcode.cn id=32 lang=c
 *
 * [32] 最长有效括号
 */

// @lc code=start

#define IS_LEFT(i)      (s[i] == '(')
#define IS_RIGHT(i)     (s[i] == ')')

int longestValidParentheses(char * s){
    short len = strlen(s);
    short *pvalue;
    short *pindex;

    if (len < 2) {
        return 0;
    }

    pvalue = malloc (sizeof(short) * len);
    if (pvalue == NULL) {
        return 0;
    }
    pindex = malloc (sizeof(short) * len);
    if (pindex == NULL) {
        free(pvalue);
        return 0;
    }

    short value = 0;
    short rmlen = 0;
    short zlen = 0;
    short idx;

    for (idx = 0; idx <= len; idx ++) {
        if (IS_LEFT(idx) || (idx == len) ||(value<=0)) {
            if (idx < len) {
                if (IS_LEFT(idx)) {
                    value ++;
                    pvalue[idx] = value;
                } else {
                    pvalue[idx] = -1;
                }
            }

            //不管是'('或')'但value==-1或结束，都代表一段完整括号的的结束，往后算一算长度
            if ((idx > 1) && IS_RIGHT(idx -1) && (pvalue[idx - 1] >= 0)) {
                //往后找一个有配对的')’，算idx，和前面一个和他匹配的'('的idx之间的差
                zlen = idx - pindex[idx -1];
                if (rmlen < zlen) {
                    rmlen = zlen;
                }
            }
        } else {
            value --;
            pvalue[idx] = value;

            //往后找到第一个和自己value一样的idx，是配对的idx
            int back_idx = idx - 1;
            while (IS_RIGHT(back_idx) || (pvalue[back_idx] > value + 1)) {
                back_idx --;
            }

            if ((back_idx > 0) && IS_RIGHT(back_idx - 1)) {
                //前面还有合法的配对，从前一个字符的pindex里面自己去取
                if (pvalue[back_idx - 1] >= 0) {
                    pindex[idx] = pindex[back_idx - 1];
                } else {    
                    pindex[idx] = back_idx;
                }
            } else {
                //前面没有合法的配对了，直接计入pindex
                pindex [idx] = back_idx;
            }
        }
    }

    free(pvalue);
    free(pindex);
    return rmlen;
}
// @lc code=end

