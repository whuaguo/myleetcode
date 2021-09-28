/*
 * @lc app=leetcode.cn id=51 lang=c
 *
 * [51] N 皇后
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

bool findQSolution(char **existQ, int totalSize, int leftSize) {

    return true;
}

char qs[100][9][9] = {0};
int qsn = 0;

char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    char ***retQ = NULL;
    int *rcs = NULL;

    qsn = 0;
    findQSolution()

    //设置好返回值
    rcs = malloc(qsn * sizeof(int));
    if (rcs == NULL) {
        return NULL;
    }

    retQ = malloc(qsn * sizeof(char **));
    if (retQ == NULL) {
        free(rcs);
        return NULL;
    }

    for (int i = 0; i < qsn; i++) {
        char **solution;
        char *sc;

        //拷贝一份答案
        solution  = malloc(n * sizeof(char *));
        sc = malloc(n * n * sizeof(char));
        if (solution == NULL || sc == NULL) {
            return NULL;
        }

        for (int j = 0; j < n; j++) {
            solution[j] = &sc[n*j];
            memcpy(&sc[n*j], qs[i][j], n);
        }

        rcs[i] = n;
        retQ[i] = solution;
    }
    *returnColumnSizes = rcs;
    *returnSize = qsn;

    return retQ;
}
// @lc code=end

