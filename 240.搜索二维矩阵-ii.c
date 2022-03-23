/*
 * @lc app=leetcode.cn id=240 lang=c
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
//#define BSEARCH

#ifdef BSEARCH
int intCompare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
#endif

bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target)
{
    for (int idx = 0; idx < matrixSize; idx++)
    {
        if (matrix[idx][0] > target)
            return false;

        if (matrix[idx][matrixColSize[idx] - 1] < target)
            continue;

#ifdef BSEARCH
        if (bsearch(&target, matrix[idx], matrixColSize[idx], sizeof(int), intCompare))
        {
            return true;
        }
#else
        int mid;
        int value;
        int left = 0;
        int right = matrixColSize[idx];
        while (left <= right)
        {
            mid = ((left + right) >> 1);
            value = matrix[idx][mid];

            if (value == target)
            {
                return true;
            }
            else if (value > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
#endif
    }

    return false;
}
// @lc code=end
