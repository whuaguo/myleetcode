/*
 * @lc app=leetcode.cn id=32 lang=c
 *
 * [32] 最长有效括号
 */

// @lc code=start


int longestValidParentheses(char * s){
    int len = strlen(s);

    if (len < 2) {
        return 0;
    }

    int value = 0;
    int mlen = 0;
    int rmlen = 0;
    int zlen = 0;
    int llen = 0;

    int max = 0;
    int cmax = 0

    for (int idx = 0; idx < len; idx ++) {
        if (s[idx] == '(') {
            value ++;
            mlen ++;
            llen ++;
        } else {
            if (value > 0) {
                value --;
                mlen ++;
                llen = 0;

                if (value == 0) {
                    zlen += mlen;
                    mlen = 0;
                } else {
                    //已经有配对，更新一下最大值
                    if (mlen - value > zlen) {
                        zlen = mlen - value;
                    }
                }
            } else {
                if (rmlen < zlen) {
                    rmlen = zlen;
                }
                mlen = 0;
                zlen = 0;
            }
        }
    }

    if (zlen > rmlen) {
        rmlen = zlen;
    }

    if (mlen - value > rmlen) {
        rmlen = mlen - value;
    }

    return rmlen;
}
// @lc code=end

