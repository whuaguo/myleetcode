/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 */

// @lc code=start

inline char *makestr (char * s, int len) {
    char *retstr;

    retstr = malloc (len + 1);
    if (retstr == NULL) {
        return NULL;
    }

    memcpy(retstr, s, len);
    retstr[len] = 0;

    return retstr;
}

int is_pstr(char * s, int len) {
    int i;

    for (i = 0 ; i < len / 2; i++) {
        if (s[i] != s [len - i - 1]) {
            //not equal, return false
            return 0;
        }
    }

    //all equal, return true
    return 1;
}

char * longestPalindrome(char * s){
    int i;
    int str_len = strlen (s);
    int max_len = 1;
    int idx = 0;

    if (str_len == 0) {
        return NULL;
    }

    if (str_len ==1) {
        return makestr(s, 1);
    }

    for (i = 0; i < str_len - max_len; i++) {
        int c_strlen = str_len - i;

        while (c_strlen > max_len) {
            if (is_pstr(s + i, c_strlen)) {
                if (c_strlen > max_len) {
                    max_len = c_strlen;
                    idx = i;
                    break;
                }
            }

            c_strlen --;
        }
    }

    return makestr(s+idx, max_len);
}
// @lc code=end

