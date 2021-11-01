/*
 * @lc app=leetcode.cn id=190 lang=c
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0;

    for (int idx = 0; idx < 32; idx++) {
        ret = ret << 1 | n & 1;
        n = n >> 1;
    }

    return ret;
}
// @lc code=end

