/*
 * @lc app=leetcode.cn id=47 lang=c
 *
 * [47] 全排列 II
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//用来做排序使用
int intcompare(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void findAnswers(int *nums, int numsSize, int *returnSize, int *answer, int *flag, int **answers) {
    for (int idx = 0; idx < numsSize; idx++) {
        if (flag[idx]) {
            continue;
        }

        if ((idx > 0) && (nums[idx] == nums[idx - 1]) && !flag[idx - 1]) {
            continue;
        }

        answer[flag[numsSize]++] = nums[idx];
        if (flag[numsSize] == numsSize) {
            int *ans = malloc(sizeof(int) * numsSize);
            assert(ans != NULL);
            memcpy(ans, answer, sizeof(int) * numsSize);

            answers[*returnSize] = ans;
            *returnSize += 1;
        } else {
            flag[idx] = 1;
            findAnswers(nums, numsSize, returnSize, answer, flag, answers);
            flag[idx] = 0;
        }
        flag[numsSize] --;
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int totalNum = 5000;

    int **ret = malloc(sizeof(int *) * totalNum);
    assert(ret != NULL);
    *returnSize = 0;

    *returnColumnSizes = malloc(sizeof(int) * totalNum);
    assert(*returnColumnSizes != NULL);

    for (int i = 0; i < totalNum; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }

    int answer[8] = {0};
    int flag[9] = {0};

    qsort(nums, numsSize, sizeof(int), intcompare);
    findAnswers(nums, numsSize, returnSize, answer, flag, ret);

    return ret;
}
// @lc code=end

