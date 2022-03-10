/*
 * @lc app=leetcode.cn id=40 lang=c
 *
 * [40] 组合总和 II
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

void findAnswers(int* candidates, int candidatesSize, int target, int* returnSize, int *returnColumnSizes, int **answer, char *flag, int answerIdx, int sum, int **answers){
    for (int idx = 0; idx < candidatesSize; idx++) {
        //数字已经在潜在答案里面
        if (flag[idx] == 1) {
            continue;
        }

        int num = candidates[idx];
        //如果前一个数字和当前数字相等，并且不再潜在答案里面，意味当前组合前面已经尝试，排除
        if ((idx > 0) && (num == candidates[idx - 1]) && !flag[idx - 1]) {
            continue;
        }

        //答案必须从小到大，排除重复答案
        if ((answerIdx > 0) &&  num < (*answer)[answerIdx - 1]) {
            continue;
        }

        int new_sum = sum + num;
        if (new_sum < target) {
            //王答案数组里面放一个可能的值，往后尝试
            flag[idx] = 1;
            (*answer)[answerIdx] = num;
            findAnswers(candidates,candidatesSize,target, returnSize, returnColumnSizes, answer, flag, answerIdx + 1, new_sum, answers);
            flag[idx] = 0;
        } else if (new_sum == target){
            //已经找到答案，记住答案，重新分配一个答案数组供继续尝试
            (*answer)[answerIdx] = num;
            answers[*returnSize] = *answer;
            returnColumnSizes[*returnSize] = answerIdx + 1;

            *answer = malloc(sizeof(int)*candidatesSize);
            assert(*answer != NULL);
            memcpy(*answer,  answers[*returnSize], sizeof(int) * answerIdx);

            *returnSize += 1;
            return;
        } else {
            return;
        }
    }

    return;
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int ** ret = malloc(200 * sizeof(int *));
    assert(ret != NULL);

    *returnColumnSizes = malloc(200 * sizeof(int));
    assert(*returnColumnSizes != NULL);

    *returnSize = 0;

    int *answer = malloc(sizeof(int)*candidatesSize);
    char *flag = malloc(candidatesSize);
    assert(answer != NULL);
    assert(flag != NULL);
    memset(flag, 0, candidatesSize);

    //先对数组排序，这样寻找答案的时候可以限定从小到大，排除重复答案
    qsort(candidates, candidatesSize, sizeof(int), intcompare);
    findAnswers(candidates,candidatesSize, target, returnSize, *returnColumnSizes, &answer, flag, 0, 0, ret);

    free(answer);
    if (0 == *returnSize) {
        free(ret);
        free(*returnColumnSizes);
        return NULL;
    } 
    
    return ret;
}
// @lc code=end

