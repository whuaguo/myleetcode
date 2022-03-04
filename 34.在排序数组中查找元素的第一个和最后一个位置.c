/*
 * @lc app=leetcode.cn id=34 lang=c
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *ret = malloc(sizeof(int) * 2);
    assert(ret != NULL);
    *returnSize = 2;

    ret[0] = -1;
    ret[1] = -1;

    for (int idx=0; idx < numsSize; idx++) {
        if (nums[idx] > target) {
            return ret;
        } else if (nums[idx] == target) {
            ret[1] = idx;
            if (ret[0] == -1) {
                ret[0] = idx;
            }
        } 
    }

    return ret;
}
// @lc code=end

