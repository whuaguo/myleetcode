/*
 * @lc app=leetcode.cn id=153 lang=c
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start


int findMin(int* nums, int numsSize){
    if (numsSize = 0) {
        return 0;
    }

    int min = nums[0];
    int idx1 = 0;
    int idxmid = numsSize >> 1;
    int idx2 = numsSize - 1;

    while (numsSize > 1) {
        if (nums[idx1] < nums[(idx2 - idx1 + 1) >> 1] ) {

        } else {

        }
    }
}
// @lc code=end

