/*
 * @lc app=leetcode.cn id=10 lang=c
 *
 * [10] 正则表达式匹配
 */

// @lc code=start


bool isMatch(char * s, char * p){
    int idx_s=0, idx_p=0;

    while (idx_s <strlen(s) || idx_p < strlen(p)) {
        while ((idx_s < strlen(s)) && ((s[idx_s] == '.') ||(s[idx_s]=='*'))) {
            idx_s++;
        }
        
        while ((idx_p < strlen(p)) && ((p[idx_p] == '.') ||(p[idx_p]=='*'))) {
            idx_p++;
        }

        if (s[idx_s] == p[idx_p]){
            idx_s++;
            idx_p++;
        } else {
            
        }
    }

    return 1;
}
// @lc code=end

