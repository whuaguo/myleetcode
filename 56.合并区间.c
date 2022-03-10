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

//用来做排序使用
int intervalcompare(const void * a, const void * b)
{
    return (*(*(int **)a) - *(*(int **)b));
}

#define INTERVAL2LIST { \
        int *interval = malloc(sizeof(int) * 2);\
        assert(interval != NULL);\
        interval[0] = interval_left;\
        interval[1] = interval_right;\
        (*returnColumnSizes)[retidx] = 2;\
        ret[retidx++] = interval;\
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    *returnSize = intervalsSize;
    if (intervalsSize <= 1) {
        *returnColumnSizes = intervalsColSize;
        return intervals;
    }

    qsort(intervals, intervalsSize, sizeof(int *), intervalcompare);

    int **ret = malloc(sizeof(int *) * intervalsSize);
    *returnColumnSizes = malloc(sizeof(int) * intervalsSize);
    assert(ret != NULL);
    assert(*returnColumnSizes != NULL);

    int retidx = 0;
    int interval_left = intervals[0][0];
    int interval_right = intervals[0][1];
    for (int idx = 1; idx < intervalsSize; idx++){
        if (intervals[idx][0] <= interval_right) {
            if (intervals[idx][1] > interval_right) {
                interval_right = intervals[idx][1];
            }
            continue;
        }
        
        INTERVAL2LIST;
        interval_left = intervals[idx][0];
        interval_right = intervals[idx][1];
    }

    INTERVAL2LIST;
    *returnSize = retidx;
    return ret;
}
// @lc code=end

