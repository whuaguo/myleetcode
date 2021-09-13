/*
 * @lc app=leetcode.cn id=6 lang=c
 *
 * [6] Z 字形变换
 */

// @lc code=start


char * convert(char * s, int numRows){
    int slen = strlen(s);
    if (!slen) {
        return NULL;
    }

    //malloc the return string
    char * rets = malloc(slen +1);
    if (!rets) {
        return NULL;
    }

    //set the tail right
    rets[slen] = 0;

    //only 1 row, just return the same string
    if (numRows <= 1) {
        memcpy(rets, s, slen);
        return rets;
    }

    //do the right thing
    int idx = 0;
    int loop_step = (numRows - 1) * 2;
    for (int i = 0; i < numRows; i++) {
        int s_idx = i;
        while (s_idx < slen) {
            rets[idx] = s[s_idx];
            idx++;

            // s_idx + step1 + step2 = s_idx + loop_step, step1 = n - 2*i, step2 = 2*i
            if ((s_idx - i) % loop_step == 0) {
                //step 1 
                int step1 = loop_step - (i << 1);
                if (step1) {
                    s_idx += step1;
                } else {
                    //if i equals (0, numrows -1), there will be no step2
                    s_idx += loop_step;
                } 
            } else {
                //step 2
                s_idx += (i << 1);
            }
        }
    }
    return rets;
}
// @lc code=end

