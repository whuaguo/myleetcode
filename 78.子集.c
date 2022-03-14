/*
 * @lc app=leetcode.cn id=78 lang=c
 *
 * [78] 子集
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/*
 * 对于一个子集，对所有元素可以选择，可以不选择，
 * 所以共有2的numsize幂个答案，每个答案对应一个小于2的numSize幂的
 * 整数，这个整数的2进制每一位对应选择或不选择这个元素
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int totalnum = 1;

    for (int i = 0; i < numsSize; i++) {
        totalnum = totalnum << 1;
    }

    int **ret = malloc(sizeof(int *) * totalnum);
    *returnColumnSizes = malloc(sizeof(int) * totalnum);
    assert(ret != NULL);
    assert(*returnColumnSizes != NULL);

    int answer[10];
    for (int num = 0; num < totalnum; num++) {
        int count = num;
        int idx = 0;
        int answerIdx = 0;
        while (count > 0) {
            if (count & 1) {
                answer[answerIdx++] = nums[idx];
            }
            idx++;
            count = count >> 1;
        }

        int *retAnswer = NULL;
        if (answerIdx) {
            retAnswer = malloc(sizeof(int) * answerIdx);
            assert(retAnswer != NULL);
            memcpy(retAnswer, answer, answerIdx * sizeof(int));
        }

        ret[num] = retAnswer;
        (*returnColumnSizes)[num] = answerIdx;
    }

    *returnSize = totalnum;
    return ret;
}
// @lc code=end

