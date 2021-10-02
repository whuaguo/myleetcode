/*
 * @lc app=leetcode.cn id=76 lang=c
 *
 * [76] 最小覆盖子串
 */

// @lc code=start


char * minWindow(char * s, char * t){
    int len;
    int sc['z' - 'A' + 1] = {0};
    int tc['z' - 'A' + 1] = {0};

    for (len = 0; len < strlen(s); len ++) {
        sc[s[len] - 'A']++;
    }

    for (len = 0; len < strlen(s); len ++) {
        tc[s[len] - 'A']++;
    }

    for (char i = 'A'; i <= 'z'; i++) {
        if (sc[i - 'A'] < tc[i - 'A']) {
            return NULL;
        }
    }

    int left = 0, right = strlen(s) - 1;

    return NULL;

}
// @lc code=end

