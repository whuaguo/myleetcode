/*
 * @lc app=leetcode.cn id=307 lang=c
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start

typedef struct
{
    int size;
    int *values;
    int *sums;
} NumArray;

NumArray *numArrayCreate(int *nums, int numsSize)
{
    NumArray *ret = malloc(sizeof(NumArray));
    assert(ret != NULL);
    ret->values = malloc(sizeof(int) * numsSize);
    assert(ret->values != NULL);
    ret->size = numsSize;
    memcpy(ret->values, nums, sizeof(int) * numsSize);

    ret->sums = malloc(sizeof(int) * numsSize);
    assert(ret->sums != NULL);

    int sum = 0;
    for (int idx = 0; idx < numsSize; idx++)
    {
        sum += nums[idx];
        ret->sums[idx] = sum;
    }

    return ret;
}

void numArrayUpdate(NumArray *obj, int index, int val)
{
    int delta = val - obj->values[index];
    obj->values[index] = val;
    for (int idx = index; idx < obj->size; idx++)
    {
        obj->sums[idx] += delta;
    }
}

int numArraySumRange(NumArray *obj, int left, int right)
{
    return obj->sums[right] - ((left == 0) ? 0 : obj->sums[left - 1]);
}

void numArrayFree(NumArray *obj)
{
    if (obj)
    {
        free(obj->sums);
        free(obj->values);
        free(obj);
    }
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * numArrayUpdate(obj, index, val);

 * int param_2 = numArraySumRange(obj, left, right);

 * numArrayFree(obj);
*/
// @lc code=end
