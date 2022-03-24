/*
 * @lc app=leetcode.cn id=275 lang=c
 *
 * [275] H 指数 II
 */

// @lc code=start

int hIndex(int *citations, int citationsSize)
{
    if (citationsSize == 0)
    {
        return 0;
    }

#ifndef QSORT
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
