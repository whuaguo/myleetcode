/*
 * @lc app=leetcode.cn id=216 lang=c
 *
 * [216] 组合总和 III
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//#define DEBUG 1
#ifdef DEBUG
#define log printf
void logAnswer(int *answer, int answerCount, int answerSum)
{
    log("The answer are %d:%d [", answerSum, answerCount);
    for (int idx = 0; idx < answerCount; idx++)
    {
        log("%d, ", answer[idx]);
    }

    log("].\n");
}
#else
#define log
#define logAnswer
#endif

void findAnswers(int k, int n, int *returnSize, int *answer, int answerCount, int answerSum, int **answers, int *returnColumnSizes)
{
    logAnswer(answer, answerCount, answerSum);
    for (int idx = answerCount ? (answer[answerCount - 1] + 1) : 1; idx <= 9; idx++)
    {
        int sum = answerSum + idx;
        log("Check number %d, sum will be %d!\n", idx, sum);
        if (sum > n)
        {
            //不可能组合，直接退出
            log("Sum is too big, not possible anymore and return!\n");
            return;
        }
        else if (sum == n)
        {
            if (answerCount + 1 != k)
            {
                //不可能组合，直接退出
                log("Sum is OK with count not ready and not possible anymore and return!\n");
                return;
            }

            //找到一个答案
            answer[answerCount] = idx;
            int *retanswer = malloc(sizeof(int) * k);
            assert(retanswer != NULL);

            memcpy(retanswer, answer, sizeof(int) * k);
            answers[*returnSize] = retanswer;
            returnColumnSizes[*returnSize] = k;
            *returnSize += 1;

            //后面不可能有其他答案
            return;
        }
        else
        {
            if ((sum + (k - answerCount - 1) * (idx + 1)) <= n)
            {
                log("Add %d into answer and continue try!\n", idx);
                answer[answerCount] = idx;
                findAnswers(k, n, returnSize, answer, answerCount + 1, sum, answers, returnColumnSizes);
            }
            else
            {
                log("Sum is %d, left number is %d, min number is %d, Not possible and stop try!\n", sum, k - answerCount - 1, idx + 1);
                return;
            }
        }
    }
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes){
    int **ret = malloc(sizeof(int *) * 100);
    *returnColumnSizes = malloc(sizeof(int) * 100);
    assert(ret != NULL);
    assert(*returnColumnSizes != NULL);

    *returnSize = 0;
    int answer[10] = {0};

    findAnswers(k, n, returnSize, answer, 0, 0, ret, *returnColumnSizes);

    return ret;
}
// @lc code=end

