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


unsigned char qs[100][10] = {0};
unsigned char qsn = 0;

static bool nQconflict(unsigned char *steps, 
                       unsigned char totalSteps, 
                       unsigned char existSteps, 
                       unsigned char key) {
    for (unsigned char i = 0; i < existSteps; i++) {
        if ((steps[i] == key) || (steps[i] - i == existSteps - key)) {
            return false;
        }
    }

    return true;
}

void findQSolution(unsigned char *steps, unsigned char totalSteps, unsigned char existSteps) {
    if (totalSteps == existSteps + 1) {
        //find one solution
        memcpy(qs[qsn], steps, totalSteps);
        qsn ++;
        return;
    }

    for (unsigned char i = 0; i < totalSteps - 1; i ++) {
        if (nQconflict(steps, totalSteps, existSteps, i)) {
            steps[existSteps] = i;
            findQSolution(steps, totalSteps, existSteps+1);
            steps[existSteps] = 0;
        }
    }

    return;
}


char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    char ***retQ = NULL;
    unsigned char *rcs = NULL;
    unsigned char steps[10] = {0};

    qsn = 0;

    findQSolution(steps, n, 0);

    if (qsn == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

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

        memset(sc, '.', n*n);
        for (int j = 0; j < n; j++) {
            solution[j] = &sc[n*j];
            sc[n*j + qs[i][j]] = 'Q';
        }

        rcs[i] = n;
        retQ[i] = solution;
    }
    *returnColumnSizes = rcs;
    *returnSize = qsn;

    return retQ;
}
// @lc code=end

