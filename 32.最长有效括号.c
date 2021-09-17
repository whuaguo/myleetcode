/*
 * @lc app=leetcode.cn id=32 lang=c
 *
 * [32] 最长有效括号
 */

// @lc code=start


int longestValidParentheses(char * s){
    int len = strlen(s);
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
    for (short idx = 0; idx < len; idx ++) {
        if (s[idx] == '(') {
            value ++;
            pvalue[idx] = value;

            if ((idx > 1) && (s[idx -1] == ')')) {
                if (pvalue[idx - 1] >= 0) {
                    zlen = idx -1 - pindex[idx -1];
                } 
                if (rmlen < zlen) {
                    rmlen = zlen;
                }
            }
        } else {
            if (value > 0) {
                value --;
                pvalue[idx] = value;
            } else {
                pvalue[idx] = -1;
            } 
        }
    }

    free(pvalue);
    free(pindex);
    return rmlen;
}
// @lc code=end

