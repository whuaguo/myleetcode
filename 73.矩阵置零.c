/*
 * @lc app=leetcode.cn id=73 lang=c
 *
 * [73] 矩阵置零
 */

// @lc code=start


void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    for (int i = 1; i < matrixSize; i++){
        for (int j = 1; j < matrixColSize[0]; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        if (matrix[i][0] == 0) {
            for (int j = 1; j < matrixColSize[0]; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < matrixColSize[0]; i ++) {
        if (matrix[0][i] == 0) {
            for (int j = 1; j < matrixSize; j++) {
                matrix[j][i] = 0;
            }
        }
    }

    return;
}
// @lc code=end

