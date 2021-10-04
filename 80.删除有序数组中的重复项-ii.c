/*
 * @lc app=leetcode.cn id=80 lang=c
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start


int removeDuplicates(int* nums, int numsSize){
    int right = 1;
    int left = 0;  
    bool dupped;

    if (numsSize < 3) {
        return numsSize;
    }

    while (right < numsSize) {
        dupped = (nums[right] == nums[left]);
        
        //移动左右指针，如果需要移动数组内的值
        left++;
        if (left != right) {
            nums[left] = nums[right];
        }
        right++;

        if (dupped) {
            //相同，移动有指针知道不相等
            while ((right < numsSize) && (nums[right] == nums[left])) {
                right ++;
            }
        }
    }

    return left + 1;
}
// @lc code=end

