/*
 * @lc app=leetcode.cn id=41 lang=c
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start


int firstMissingPositive(int* nums, int numsSize){
    char *pflag;

    pflag = malloc(numsSize);
    if (pflag == NULL) {
        return 0;
    }
    
    memset(pflag, 0, numsSize);

    for (int i = 0; i < numsSize; i ++) {
        if ((nums[i] > 0) && (nums[i] <= numsSize)) {
            pflag[nums[i] - 1] = 1;
        }
    }

    for (int i = 0; i < numsSize; i ++) {
        if (pflag[i] == 0) {
            free(pflag);
            return i + 1;
        }
    }
    
    free(pflag);
    return numsSize+1;
}
// @lc code=end

