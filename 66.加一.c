/*
 * @lc app=leetcode.cn id=66 lang=c
 *
 * [66] 加一
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    int idx;
    for (idx = digitsSize - 1; idx >= 0; idx--)
    {
        if (digits[idx] != 9)
        {
            break;
        }
    }

    // printf("idx of no-9 is %d.\n", idx);
    *returnSize = digitsSize + ((idx >= 0) ? 0 : 1);
    int *ret = malloc(sizeof(int) * (*returnSize));
    assert(ret != NULL);

    memset(ret, 0, *returnSize * sizeof(int));
    if (idx > 0)
    {
        memcpy(ret, digits, idx * sizeof(int));
    }

    if (idx >= 0)
    {
        ret[idx] = digits[idx] + 1;
    }
    else
    {
        ret[0] = 1;
    }

    return ret;
}
// @lc code=end
