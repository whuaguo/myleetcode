/*
 * @lc app=leetcode.cn id=274 lang=c
 *
 * [274] H 指数
 */

// @lc code=start
#ifdef QSORT
int intCompare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
#endif

int hIndex(int *citations, int citationsSize)
{
    if (citationsSize == 0)
    {
        return 0;
    }

    qsort(citations, citationsSize, sizeof(int), intCompare);

#ifdef QSORT
    int idx;
    for (idx = citationsSize - 1; idx >= 0; idx--)
    {
        if (citations[idx] < (citationsSize - idx))
        {
            break;
        }
    }
    return citationsSize - idx - 1;
#else
    int left = 0;
    int right = citationsSize;
    int mid;
    while (left < right)
    {
        mid = ((left + right) >> 1);
        if (citations[mid] >= (citationsSize - mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return citationsSize - right;
#endif
}
// @lc code=end
