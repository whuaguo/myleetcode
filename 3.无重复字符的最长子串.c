/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start


int lengthOfLongestSubstring(char * s){
    int max = 1;
    int len;
    int maxi = 1;
    int j = 1, k;

    if (!s) {
        return 0;
    }

    len = strlen(s);
    if (len ==0) {
        return 0;
    }

    for (int i = 0; i < len-1; ) {
        //因为J,K字符相同，I已经挪到K+1,J不用重置，继续往下查找
        for (; j < len; j++) {
            for (k = i; k < j; k++) {
                if (s[k] == s[j]) {
                    break;
                }
            }

            if ((k < j)) {
                break;
            } 
        }

        maxi = j - i;
        max = (max > maxi) ? max: maxi;
        if (k < j) {
            //k，j相同，k之前开始不可能有更长的可能，直接跳到K+1
            i = k + 1;
        } else {
            //没有相同的字符，意味已到尾部，在更短的字符串里面查找没有意义，直接返回
            return max;
        }
    }

    return max;
}
// @lc code=end

