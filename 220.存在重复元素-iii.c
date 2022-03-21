/*
 * @lc app=leetcode.cn id=220 lang=c
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
//#define QMAP 1
#define MAP 1
#define QSORT 1

int intCompare(const void *a, const void *b)
{
    return (*(int *)a > *(int *)b) ? 1 : ((*(int *)a == *(int *)b) ? 0 : -1);
}
#define absCompare(a, b, t) ((a & 0x80000000) ^ (b & 0x80000000)) ? (a <= b + t) : ((a - b) <= t)

#if (defined MAP || defined QMAP)
typedef struct node
{
    int idx;
    int value;
} mapNode;

int pmapNodeCompare(const void *a, const void *b)
{
    mapNode *p1 = *(mapNode **)a;
    mapNode *p2 = *(mapNode **)b;
    return (p1->idx > p2->idx) ? 1 : ((p1->idx == p2->idx) ? 0 : -1);
}

#define mapNodeCompare intCompare
#define getIdx(u, size) (((size) < 0) ? (((u) >= 0) ? 0 : -1) : (((u) >= 0) ? ((u) / (size)) : ((((u) + 1) / (size)) - 1)))
#define CLEANUP      \
    {                \
        free(lists); \
    }

bool mapNodeAbsCompare(mapNode *lists, int idx, int t)
{
    return (lists[idx + 1].idx == (lists[idx].idx + 1)) ? absCompare(lists[idx + 1].value, lists[idx].value, t) : false;
}

bool pMapNodeAbsCompare(mapNode **plists, int idx, int t) {
    return (plists[idx + 1]->idx == (plists[idx]->idx + 1)) ? absCompare(plists[idx + 1]->value, plists[idx]->value, t) : false;
}
#endif

bool containsNearbyAlmostDuplicate(int *nums, int numsSize, int k, int t)
{
    if (k == 0)
        return false;
#if (defined QMAP)
    int size = (k < numsSize) ? (k + 1) : numsSize;
    int dis = (t == 0x7fffffff) ? -1 : (t + 1);

    mapNode *lists = malloc(sizeof(mapNode) * (size));
    mapNode **plists = malloc(sizeof(mapNode *) *(size));
    assert(lists != NULL);
    assert(plists != NULL);

    for (int idx = 0; idx < size; idx++)
    {
        lists[idx].idx = getIdx(nums[idx], dis);
        lists[idx].value = nums[idx];
        plists[idx] = &lists[idx];
    }

    qsort(plists, size, sizeof(mapNode *), pmapNodeCompare);

    for (int idx = 0; idx < size - 1; idx++)
    {
        if ((plists[idx]->idx == plists[idx + 1]->idx) || pMapNodeAbsCompare(plists, idx, t))
        {
            CLEANUP;
            return true;
        }
    } 

    mapNode **end = plists + k;
    for (int idx = size; idx < numsSize; idx++)
    {
        mapNode *keyNode = &lists[idx % size];
        int newIdx = getIdx(nums[idx], dis);
        mapNode **item;
        
        if (keyNode->idx != newIdx)
        {
            mapNode *newNode = &newIdx;
            if (bsearch(&newNode, plists, size, sizeof(mapNode *), pmapNodeCompare))
            {
                CLEANUP;
                return true;
            }

            item = bsearch(&keyNode, plists, size, sizeof(mapNode*), pmapNodeCompare);
            if (keyNode->idx > newIdx) {
                while (item > plists)
                {
                    if ((*(item - 1))->idx < newIdx)
                        break;

                    *item = *(item - 1);
                    item--;
                }
            } else {
                while (item < end)
                {
                    if ((*(item + 1))->idx > newIdx)
                        break;

                    *item = *(item + 1);
                    item++;
                }
            }
        }
        else 
        {
            item = bsearch(&keyNode, plists, size, sizeof(mapNode*), pmapNodeCompare);
        }

        if ((item != plists) && (absCompare(nums[idx], (*(item - 1))->value, t))||
            (item != end)    && (absCompare((*(item + 1))->value, nums[idx], t)))
        {
            CLEANUP;
            return true;
        }

        keyNode->value = nums[idx];
        keyNode->idx = newIdx;
        *item = keyNode;
    }

    CLEANUP;
    return false;
#elif (defined MAP)
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

            if (item->idx > newIdx)
            {
                while (item > lists)
                {
                    if ((*(item - 1)).idx < newIdx)
                        break;

                    *item = *(item - 1);
                    item--;
                }
            }
            else
            {
                while (item < end)
                {
                    if ((*(item + 1)).idx > newIdx)
                        break;

                    *item = *(item + 1);
                    item++;
                }
            }

            item->idx = newIdx;
        }

        if ((item != lists) && (absCompare(nums[idx], (*(item - 1)).value, t)) ||
            (item != end) && (absCompare((*(item + 1)).value, nums[idx], t)))
        {
            CLEANUP;
            return true;
        }

        idxs[idx] = newIdx;
        item->value = nums[idx];
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

        if ((item != lists) && (absCompare(new, *(item - 1), t))||
            (item != (lists + k)) && (absCompare(*(item + 1), new, t)))
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
// @lc code=end
