/*
 * @lc app=leetcode.cn id=213 lang=c
 *
 * [213] 打家劫舍 II
 */

// @lc code=start


int rob(int* nums, int numsSize){
    switch (numsSize)
    {
        case 0:
            return 0;
        
        case 1:
            return nums[0];

        case 2:
            return nums[0]>nums[1]? nums[0]:nums[1];
    }

    int dp1[100] = {0};     //不抢第一家
    int dp2[100] = {0};     //不抢最后一家
    dp1[0] = 0;
    dp1[1] = nums[1];

    for (int i = 2; i < numsSize; i++) {
        dp1[i] = dp1[i-1] > dp1[i-2]+nums[i] ? 
                 dp1[i-1] :
                 dp1[i-2] + nums[i]; 
    }

    dp2[0] = 0;
    dp2[1] = nums[0];
    for (int j = 2; j < numsSize; j++) {
        dp2[j] = dp2[j-1] > dp2[j-2]+nums[j-1] ? 
                 dp2[j-1] : 
                 dp2[j-2]+ nums[j-1];
    }

    return dp1[numsSize - 1] > dp2[numsSize - 1] ? 
           dp1[numsSize - 1] : 
           dp2[numsSize - 1];
}
// @lc code=end

