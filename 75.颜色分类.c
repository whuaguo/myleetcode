/*
 * @lc app=leetcode.cn id=75 lang=c
 *
 * [75] 颜色分类
 */

// @lc code=start
void sortColors(int* nums, int numsSize){
    int last0 = 0, left = 0, right = numsSize - 1;
    while (left <= right) {
        if(nums[left] == 0){
            nums[left] = nums[last0];
            nums[last0] = 0;
            last0++;
            left++;
        } else if(nums[left] == 2){
            nums[left] = nums[right];
            nums[right] = 2;
            right--;
        } else {
            left++;
        }
    }
}
// @lc code=end

