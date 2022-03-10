/*
 * @lc app=leetcode.cn id=46 lang=c
 *
 * [46] 全排列
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//#define DEBUG

void findAnswers(int *nums, int numsSize, int *returnSize, int *answer, int *flag, int **answers) {
    for (int idx = 0; idx < numsSize; idx++) {
        if (flag[idx]) {
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

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int totalNum = 1;

    for (int i = 2; i <= numsSize; i++) {
        totalNum *= i;
    }

    int **ret = malloc(sizeof(int *) * totalNum);
    assert(ret != NULL);
    *returnSize = 0;

    *returnColumnSizes = malloc(sizeof(int) * totalNum);
    assert(*returnColumnSizes != NULL);

    for (int i = 0; i < totalNum; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }

    int answer[6] = {0};
    int flag[7] = {0};

    findAnswers(nums, numsSize, returnSize, answer, flag, ret);

    return ret;
}
// @lc code=end

