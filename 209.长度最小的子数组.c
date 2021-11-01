/*
 * @lc app=leetcode.cn id=209 lang=c
 *
 * [209] 长度最小的子数组
 */

// @lc code=start


int minSubArrayLen(int target, int* nums, int numsSize){
    int left = -1;
    int right = -1;
    int sum = 0;
    int min = 0x7fffffff;
    
    while (1) {
        while (sum < target) {
            right ++;
            if (right < numsSize) {
                sum += nums[right];
            } else {
                return (min == 0x7fffffff) ? 0: min;
            }
        }

        if (min > (right - left)) {
            min = right - left;
        }

        while (sum >= target) {
            left++;
            sum -= nums[left];

            if ((min > (right - left)) && (sum >= target)) {
                min = right - left;
            }
        }
    }

    return 0;
}
// @lc code=end

