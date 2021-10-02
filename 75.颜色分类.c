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
            nums[left++] = 1;
            nums[last0++] = 0;
        } else if(nums[left] == 2){
            //找到第一个非2
            while (nums[right] == 2 && (right > left)) {
                right --;
            }

            //交换一下
            nums[left] = nums[right];
            nums[right] = 2;
            right--;
        } else {
            //移动
            left++;
        }
    }
}
// @lc code=end

