/*
 * @lc app=leetcode.cn id=154 lang=c
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start


int findMin(int* nums, int numsSize){
    int idx1 = 0;
    int idx2 = numsSize - 1;

    while ((idx1 < idx2) && (nums[idx1] == nums[idx2])) {
        idx1++;
    }

    while ((idx1 < idx2) && (nums[idx1] >= nums[idx2])) {
        int idx_mid = (idx1 + idx2) >> 1;

        if (nums[idx1] <= nums[idx_mid]) {
            idx1 = idx_mid + 1;
        } else {
            idx2 = idx_mid;
        }
    }

    return nums[idx1];
}
// @lc code=end
