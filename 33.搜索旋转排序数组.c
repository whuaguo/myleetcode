/*
 * @lc app=leetcode.cn id=33 lang=c
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start

int search(int *nums, int numsSize, int target)
{
    int right = 0;
    int left = numsSize - 1;

    while (right <= left) {
        if (target == nums[right]) {
            return right;
        }

        if (target == nums[left]) {
            return left;
        }

        if (nums[right] < nums[left]) {
            // right already less than left, the arry is already in sequence
            if (target < nums[right] || target > nums[left]) {
                return -1;
            }

            int mid = (right + left) >> 1;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] > target) {
                left = mid - 1;
            } else {
                right = mid + 1;
            }
            continue;
        } 

        if (target < nums[right] && target > nums[left]) {
            return -1;
        }

        int mid = (right + left) >> 1;
        if (nums[mid] == target) {
            return mid;
        }

        if (nums[mid] < nums[left]) {
            //左边升序长度小于右边升序长度
            if ((target > nums[mid]) && (target < nums[left])) {
                right = mid + 1;
            } else {
                left = mid - 1;
            }
        } else {
            if (target > nums[right] && target < nums[mid]) {
                left = mid - 1;
            } else {
                right = mid + 1;
            }
        }
    }

    return -1;
}
// @lc code=end
