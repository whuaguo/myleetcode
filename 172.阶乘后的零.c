/*
 * @lc app=leetcode.cn id=172 lang=c
 *
 * [172] 阶乘后的零
 */

// @lc code=start


int trailingZeroes(int n){
    int num[10] = {0};
    int idx;
    int ret = 0;

    for (idx = 0; idx < 10; idx++) {
        n = n / 5;
        num[idx] = n;
        if (n == 0) {
            break;
        }
    } 

    for (int i = 0; i <= idx; i++) {
        ret += num[i];
    }

    return ret;
}
// @lc code=end
