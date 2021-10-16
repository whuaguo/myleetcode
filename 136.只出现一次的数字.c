/*
 * @lc app=leetcode.cn id=136 lang=c
 *
 * [136] 只出现一次的数字
 */

// @lc code=start


int singleNumber(int* nums, int numsSize){
    int xornum = 0;

    for (int idx = 0; idx < numsSize; idx++) {
        xornum ^= nums[idx];
    }

    return xornum;
}
// @lc code=end

