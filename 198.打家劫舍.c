/*
 * @lc app=leetcode.cn id=198 lang=c
 *
 * [198] 打家劫舍
 */

// @lc code=start


int rob(int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    } else if (numsSize == 1) {
        return nums[0];
    }

    int max[100];

    max[0] = nums[0];
    max[1] = (nums[0] > nums[1])? nums[0]: nums[1];

    for (int idx = 2; idx < numsSize; idx++) {
        max[idx] = (max[idx - 1] > max[idx - 2] + nums[idx]) ? max[idx - 1] : max[idx - 2] + nums[idx];
    }

    return max[numsSize - 1];
}
// @lc code=end

