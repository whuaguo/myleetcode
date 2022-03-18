/*
 * @lc app=leetcode.cn id=220 lang=c
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
#define MAP 1
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

#define mapNodeCompare intCompare
#define absCompare(a, b, t) ((a & 0x80000000) ^ (b & 0x80000000)) ? (a <= b + t) : ((a - b) <= t)
#define getIdx(u, size) (((size) < 0) ? (((u) >= 0) ? 0 : -1) : (((u) >= 0) ? ((u) / (size)) : ((((u) + 1) / (size)) - 1)))
#define CLEANUP      \
    {                \
        free(lists); \
        free(idxs);  \
    }

bool mapNodeAbsCompare(mapNode *lists, int idx, int t)
{
    return (lists[idx + 1].idx == (lists[idx].idx + 1)) ? absCompare(lists[idx + 1].value, lists[idx].value, t) : false;
}

bool containsNearbyAlmostDuplicate(int *nums, int numsSize, int k, int t)
{
    if (k == 0)
        return false;

#if (defined MAP)
    int size = (k < numsSize) ? (k + 1) : numsSize;
    int dis = (t == 0x7fffffff) ? -1 : (t + 1);

    int *idxs = malloc(sizeof(int) * numsSize);
    mapNode *lists = malloc(sizeof(mapNode) * (size));
    assert(idxs != NULL);
    assert(lists != NULL);

    for (int idx = 0; idx < size; idx++)
    {
        idxs[idx] = getIdx(nums[idx], dis);
        lists[idx].idx = idxs[idx];
        lists[idx].value = nums[idx];
    }

    qsort(lists, size, sizeof(mapNode), mapNodeCompare);

    for (int idx = 0; idx < size - 1; idx++)
    {
        if (lists[idx].idx == lists[idx + 1].idx || mapNodeAbsCompare(lists, idx, t))
        {
            CLEANUP;
            return true;
        }
    }

    mapNode *end = lists + k;
    for (int idx = size; idx < numsSize; idx++)
    {
        mapNode *item = bsearch(&idxs[idx - size], lists, size, sizeof(mapNode), intCompare);

        int newIdx = getIdx(nums[idx], dis);
        if (item->idx != newIdx)
        {
            if (bsearch(&newIdx, lists, size, sizeof(mapNode), intCompare))
            {
                CLEANUP;
                return true;
            }

            while (item > lists)
            {
                if ((*(item - 1)).idx == newIdx)
                {
                    CLEANUP;
                    return true;
                }

                if ((*(item - 1)).idx < newIdx)
                    break;

                memcpy(item, item - 1, sizeof(mapNode));
                item--;
            }

            while (item < end)
            {
                if ((*(item + 1)).idx == newIdx)
                {
                    CLEANUP;
                    return true;
                }

                if ((*(item + 1)).idx > newIdx)
                    break;

                memcpy(item, item + 1, sizeof(mapNode));
                item++;
            }
        }

        idxs[idx] = newIdx;
        item->idx = newIdx;
        item->value = nums[idx];
        if ((item != lists) && (absCompare(nums[idx], (*(item - 1)).value, t)))
        {
            CLEANUP;
            return true;
        }

        if ((item != end) && (absCompare((*(item + 1)).value, nums[idx], t)))
        {
            CLEANUP;
            return true;
        }
    }

    CLEANUP;
    return false;
#elif (defined QSORT)
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

        if ((item != lists) && (absCompare(new, *(item - 1), t)))
            return true;

        if ((item != (lists + k)) && (absCompare(*(item + 1), new, t)))
            return true;

        *item = new;
    }

    return false;
#else
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

    for (int idx = 1; idx < numsSize; idx++)
    {
        int fromidx = (idx > k) ? (idx - k) : 0;
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

    return false;
#endif
}
= // @lc code=end
