/*
 * @lc app=leetcode.cn id=7 lang=c
 *
 * [7] 整数反转
 */

// @lc code=start
#define MAX_RET  (0x7fffffff / 10)
#define MIN_RET  ((int)0x80000000 / 10)

int reverse(int x){
    int ret = 0;

    while(x) {
        if ((ret <= MAX_RET) && (ret >= MIN_RET)) {
            ret = ret * 10 + x %10;
            x = x/10;
        } else {
            return 0;
        }
    }

    return ret;
}
// @lc code=end

