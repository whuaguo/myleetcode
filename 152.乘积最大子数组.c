/*
 * @lc app=leetcode.cn id=152 lang=c
 *
 * [152] 乘积最大子数组
 */

// @lc code=start


int maxProduct(int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }

    int num = 1;  
    int max = 0x80000000;
    
    for(int idx = 0; idx < numsSize; idx ++){
        num *= nums[idx];
        if (max < num) {
            max = num;
        }
        
        if (!nums[idx]) {
            num = 1;
        }
    }

    num = 1;
    for(int idx = numsSize - 1; idx >= 0; idx --){
        num *= nums[idx];
        if ( max < num) {
            max = num;
        }
        
        if(!nums[idx]) {
            num = 1;
        }
    }  

    return max;
}
// @lc code=end

