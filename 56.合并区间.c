/*
 * @lc app=leetcode.cn id=56 lang=c
 *
 * [56] 合并区间
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    *returnSize = intervalsSize;
    if (intervalsSize <= 1) {
        *returnColumnSizes = intervalsColSize;
        return intervals;
    }

    int **ret = malloc(sizeof(int *) * intervalsSize);
    *returnColumnSizes = malloc(sizeof(int) * intervalsSize);
    assert(ret != NULL);
    assert(*returnColumnSizes != NULL);

    int retidx = 0;
    int idx_left = 0;
    int idx_right = 1;
    while (idx_right < intervalsSize) {
        while ((intervals[idx_right][0] <= intervals[idx_right -1][1]) {
            idx_right++;
        } 
        
        int *interval = malloc(sizeof(int) * 2);
        assert(interval != NULL);

        interval[0] = intervals[idx - 1][0];
        interval[1] = intervals[idx - 1][1];
        ret[retidx++] = interval;
    }

    return ret;
}
// @lc code=end

