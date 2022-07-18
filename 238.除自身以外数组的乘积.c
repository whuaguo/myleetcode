/*
 * @lc app=leetcode.cn id=238 lang=c
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *productExceptSelf(int *nums, int numsSize, int *returnSize)
{
    int *ret = malloc(numsSize * sizeof(int));
    assert(ret);
    *returnSize = numsSize;

    int zc = 0;
    int val = 1;
    for (int idx = 0; idx < numsSize; idx++)
    {
        if (nums[idx])
        {
            val *= nums[idx];
        }
        else if (++zc > 1)
        {
            memset(ret, 0, sizeof(int) * numsSize);
            return ret;
        }
    }

    for (int idx = 0; idx < numsSize; idx++)
    {
        ret[idx] = (zc == 1) ? (nums[idx] ? 0 : val) : val / nums[idx];
    }

    return ret;
}
// @lc code=end
