/*
 * @lc app=leetcode.cn id=42 lang=c
 *
 * [42] 接雨水
 */

// @lc code=start

int trap(int* height, int heightSize){
    int left = 0;
    int right = 1;
    int sum = 0;
    int partsum = 0;

    while (right < heightSize) {
        if (height[right] < height[left]) {
            partsum += height[left] - height[right++];
        } else {
            left = right ++;
            sum += partsum;
            partsum = 0;
        }
    }

    int maxh = left;

    right--;
    left = right - 1;
    while (left > maxh) {
        if (height[left] < height[right]) {
            sum += height[right] - height[left--];
        } else {
            right = left--;
        }
    }

    return sum;
}
// @lc code=end

