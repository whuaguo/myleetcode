/*
 * @lc app=leetcode.cn id=9 lang=c
 *
 * [9] 回文数
 */

// @lc code=start


bool isPalindrome(int x){
    if (x < 0) {
        return 0;
    }

    int n = x;
    int idx = 0;
    char s[20] = {0};

    while (x >0) {
        s[idx++] = x % 10;
        x = x / 10;
    }

    for (int i=0; i < (idx / 2); i++) {
        if (s[i] != s[idx - i -1]) {
            return 0;
        }
    }
    
    return 1;
}
// @lc code=end

