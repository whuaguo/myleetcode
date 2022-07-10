/*
 * @lc app=leetcode.cn id=88 lang=c
 *
 * [88] 合并两个有序数组
 */

// @lc code=start

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    int idx1 = m - 1;
    int idx2 = n - 1;

    for (int idx = m + n - 1; (idx >= 0) && (idx2 >= 0); idx--)
    {
        nums1[idx] = (idx1 < 0 || nums1[idx1] < nums2[idx2])
                         ? nums2[idx2--]
                         : nums1[idx1--];
    }

    return;
}
// @lc code=end
