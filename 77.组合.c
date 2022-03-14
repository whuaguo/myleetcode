/*
 * @lc app=leetcode.cn id=77 lang=c
 *
 * [77] 组合
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void findAnswers(int n, int k, int *returnSize, int *returnColumnSizes, int **ret, int *answer, int *count) {
    int num = *count;
    int idx = (num == 0) ? 1: answer[num - 1] + 1; //按序找答案
    int needNum = k - num;

    for (; idx < n -  needNum + 2; idx++) {
        answer[num] = idx;
        if (needNum > 1) {
            *count += 1;
            findAnswers(n, k, returnSize, returnColumnSizes, ret, answer, count);
            *count -= 1;
        } else { 
            int *answer1 = malloc(sizeof(int) * k);
            assert(answer1 != NULL);
            memcpy(answer1, answer, sizeof(int) * k);
            ret[*returnSize] = answer1;
            returnColumnSizes[*returnSize] = k;
            *returnSize += 1;
        }
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    int answer[21] = {0};
    int count = 0;

    int **ret = malloc(sizeof(int *)*5000);
    *returnColumnSizes = malloc(sizeof(int)*5000);
    assert(ret != NULL);
    assert(*returnColumnSizes != NULL);
    *returnSize = 0;
    findAnswers(n, k, returnSize, *returnColumnSizes, ret, answer, &count);

    return ret;
}
// @lc code=end

