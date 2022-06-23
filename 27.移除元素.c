/*
 * @lc app=leetcode.cn id=27 lang=c
 *
 * [27] 移除元素
 */

// @lc code=start

int removeElement(int *nums, int numsSize, int val)
{
    int right = -1;

    for (int left = 0; left < numsSize; left++)
    {
        if (nums[left] == val)
        {
            continue;
        }

        right++;
        if (left != right)
        {
            nums[right] = nums[left];
        }
    }

    return right + 1;
}
// @lc code=end
