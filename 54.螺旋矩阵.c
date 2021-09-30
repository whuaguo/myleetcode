/*
 * @lc app=leetcode.cn id=54 lang=c
 *
 * [54] 螺旋矩阵
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int *ret;
    int retsize;

    retsize = matrixSize * matrixColSize[0];
    ret = malloc(sizeof(int) * retsize);
    if (ret == NULL) {
        return NULL;
    }
    *returnSize = retsize;

    int istart = 0;
    int jstart = 0;
    int iend = matrixSize;
    int jend = matrixColSize[0];
    int lstart = 0;

    while ((istart < iend) && (jstart < jend)) {
        int i, j;
        //上边
        for (j = jstart; j < jend; j++) {
            ret[lstart++] = matrix[istart][j];
        }
        istart++;

        //右边
        for (i = istart; i < iend; i++)
        {
            ret[lstart++] = matrix[i][jend - 1];
        }
        jend--;
        
        //下边
        if (iend > istart) {
            for (j = jend - 1; j >= jstart; j--) {
                ret[lstart++] = matrix[iend - 1][j];
            }
        }
        iend--;

        //左边
        if (jend >jstart) {
            for (i = iend - 1; i >= istart; i--){
                ret[lstart++] = matrix[i][jstart];
            }
        }
        jstart++;
    }

    return ret;
}
// @lc code=end

