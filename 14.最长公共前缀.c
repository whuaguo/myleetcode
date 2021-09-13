/*
 * @lc app=leetcode.cn id=14 lang=c
 *
 * [14] 最长公共前缀
 */

// @lc code=start


char * longestCommonPrefix(char ** strs, int strsSize){
    char *pstr;
    char value;
    int match = 1;
    int len=0;

    if (strsSize == 0 || strs == NULL) {
        goto ret;
    }

    for (int i = 0; i < strsSize; i++) {
        if (!strs[i]) {
            //任何一个字符串为空，直接返回NULL
            goto ret;
        }
    }

    while (match) {
        int end = 0;
        value = strs[0][len];
        for (int i = 1; i < strsSize; i++) {
            if (strs[i][len] != value) {
                match = 0;
                break;
            }
        }

        //all value == 0; reach the end of all strs, need break;
        if (value==0) {
            break;
        }

        //if no not-match, continue, otherwise, break;
        if (match) {
            len ++;
        } else {
            break;
        }
    }

ret:
    pstr = malloc(len+1);
    if (pstr == NULL) {
        return NULL;
    }

    if (len) {
        memcpy(pstr, strs[0], len);
    }
    pstr[len] = 0;

    return pstr;
    
}

// @lc code=end

