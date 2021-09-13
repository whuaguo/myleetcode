/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    for (int i = 0; i < numsSize - 1; i++)
    {
        int expect = target - nums[i];
           
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] == expect) {
                int *returnnums;
                returnnums = malloc(sizeof(int)<<1);
                
                if (returnnums) {
                    returnnums[0] = i;
                    returnnums[1] = j;
                    *returnSize = 2;
                    return returnnums;
                } else {
                    return 0;
                }
            }
        }
    }
    
    return 0;
}
// @lc code=end

