/*
 * @lc app=leetcode.cn id=74 lang=c
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
int intCompare(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int last  = matrixColSize[0] - 1;
    int idx;

    for (idx = 0; idx < matrixSize; idx++) {
        if (target < matrix[idx][0]) {
            return false;
        }

        if (target == matrix[idx][last]) {
            return true;
        } else if (target < matrix[idx][last]) {
            break;
        }
    }

    if (idx == matrixSize) {
        return false;
    }

    return (NULL != bsearch (&target, matrix[idx], matrixColSize[0], sizeof (int), intCompare) );
}
// @lc code=end

