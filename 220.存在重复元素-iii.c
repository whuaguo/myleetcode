/*
 * @lc app=leetcode.cn id=220 lang=c
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
//#define MAP 1
#define QSORT 1

int intCompare(const void *a, const void *b)
{
    return (*(int *)a > *(int *)b) ? 1 : ((*(int *)a == *(int *)b) ? 0 : -1);
}

typedef struct node
{
    int idx;
    int value;
} mapNode;

int mapNodeCompare(const void *a, const void *b)
{
    return (*(int *)a > *(int *)b);
}

#define absCompare(a, b, t) ((a & 0x80000000) ^ (b & 0x80000000)) ? (a <= b + t) : ((a - b) <= t)

bool containsNearbyAlmostDuplicate(int *nums, int numsSize, int k, int t)
{
#if (defined MAP)
#elif (defined QSORT)
    if (k == 0)
        return false;

    if (t == 0)
    {
        for (int idx = 1; idx < numsSize; idx++)
        {
            int fromidx = (idx > k) ? (idx - k) : 0;
            for (int i = fromidx; i < idx; i++)
            {
                if (nums[i] == nums[idx])
                {
                    return true;
                }
            }
        }
        return false;
    }

    int size = (k < numsSize) ? (k + 1) : numsSize;
    int *lists = malloc(sizeof(int) * size);
    assert(lists != NULL);

    memcpy(lists, nums, size * sizeof(int));

    qsort(lists, size, sizeof(int), intCompare);
    for (int idx = 0; idx < size - 1; idx++)
    {
        if (absCompare(lists[idx + 1], lists[idx], t))
        {
            return true;
        }
    }

    for (int idx = size; idx < numsSize; idx++)
    {
        int *item = (int *)bsearch(&nums[idx - size], lists, size, sizeof(int), intCompare);

        int new = nums[idx];
        while (item > lists)
        {
            if (*(item - 1) <= new)
                break;

            *item = *(item - 1);
            item = item - 1;
        }

        while (item < lists + k)
        {
            if (*(item + 1) >= new)
                break;

            *item = *(item + 1);
            item = item + 1;
        }

        bool left = (item == lists) ? false : (absCompare(new, *(item - 1), t));
        bool right = (item == (lists + k)) ? false : (absCompare(*(item + 1), new, t));

        if (left || right)
            return true;

        *item = new;
    }

    return false;
#else
    if (numsSize <= 1)
        return false;

    for (int idx = 1; idx < numsSize; idx++)
    {
        int fromidx = (idx > k) ? (idx - k) : 0;
        if (!t)
        {
            for (int i = fromidx; i < idx; i++)
            {
                if (nums[i] == nums[idx])
                {
                    return true;
                }
            }
        }
        else
        {
            long min, max;
            min = (long)nums[idx] - t;
            max = (long)nums[idx] + t;

            for (int i = fromidx; i < idx; i++)
            {
                if (nums[i] >= min && nums[i] <= max)
                {
                    return true;
                }
            }
        }
    }

    return false;
#endif
}
= // @lc code=end
