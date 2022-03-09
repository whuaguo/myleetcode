/*
 * @lc app=leetcode.cn id=22 lang=c
 *
 * [22] 括号生成
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void findAnswer(int rights, int lefts, int n, int *idx, char **answer, char **answers) {
    if (rights + lefts == (n << 1)) {
        (*answer)[(n << 1)] = '\0';
        answers[*idx] = *answer;

        *answer = malloc((n << 1) + 1);
        assert(*answer != NULL);

        strcpy(*answer, answers[*idx]);
        *idx += 1;

        return;
    }

    if (rights < n) {
        (*answer)[rights+lefts] = '(';
        findAnswer(rights+1, lefts, n, idx, answer, answers);
    }

    if (lefts < rights) {
        (*answer)[rights+lefts] = ')';
        findAnswer(rights, lefts+1, n, idx, answer, answers);
    }

    return;
}

char ** generateParenthesis(int n, int* returnSize){
    char **ret = malloc(2000 * sizeof(char *));
    assert(ret != NULL);

    char *answer = malloc((n << 1) + 1);
    assert(answer != NULL);

    *returnSize = 0;
    findAnswer(0, 0, n, returnSize, &answer, ret);

    return ret;
}
// @lc code=end

