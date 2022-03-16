/*
 * @lc app=leetcode.cn id=218 lang=c
 *
 * [218] 天际线问题
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void addItem2List(int **ret, int *returnSize, int *returnColumnSizes, int right, int height)
{
    if (!(*returnSize) || (right != ret[*returnSize - 1][0]))
    {
        int *block = malloc(sizeof(int) * 2);
        assert(block != NULL);
        block[0] = right;
        block[1] = height;
        ret[*returnSize] = block;
        returnColumnSizes[*returnSize] = 2;
        *returnSize += 1;
    }
    else
    {
        ret[*returnSize - 1][0] = right;
        ret[*returnSize - 1][1] = height;
    }
}

void addRight2Stack(int *hStack, int *rStack, int *stackSize, int right, int height)
{
    int idx = *stackSize - 1;
    int reduce = 0;
    int mvCount = 0;
    while (idx >= 0)
    {
        if (right < rStack[idx])
        {
            if (height <= hStack[idx])
            {
                //在高度以下，不用考虑，已经被idx对应的边缘覆盖
                return;
            }

            //跳出做插入处理
            break;
        }

        if (height >= hStack[idx])
        {
            //比已经存在的高，可以覆盖这个边缘，需要减掉已经存在的这个边
            reduce++;
        }
        else
        {
            //没有覆盖，那么需要移动的个数
            mvCount++;
        }

        idx--;
    }

    if (!reduce)
    {
        //如果上移移idx之前的边缘
        int iidx = *stackSize - 1;
        while (iidx > idx)
        {
            hStack[iidx + 1] = hStack[iidx];
            rStack[iidx + 1] = rStack[iidx];
            iidx--;
        }
        *stackSize += 1;
    }
    else
    {
        *stackSize -= --reduce;
    }

    rStack[++idx] = right;
    hStack[idx] = height;
    if (reduce)
    {
        while (mvCount--)
        {
            ++idx;
            hStack[idx] = hStack[idx + reduce];
            rStack[idx] = rStack[idx + reduce];
        }
    }

    return;
}

int** getSkyline(int** buildings, int buildingsSize, int* buildingsColSize, int* returnSize, int** returnColumnSizes){
    int hStack[20000] = {0};
    int rStack[20000] = {0};
    int stackSize = 0; //右边边界乱序，用小顶堆

    int **ret = malloc(sizeof(int *) * 10000);
    assert(ret != NULL);
    *returnColumnSizes = malloc(sizeof(int) * 10000);
    assert(*returnColumnSizes != NULL);
    *returnSize = 0;

    int height = 0;
    for (int idx = 0; idx < buildingsSize; idx++) {
        while (stackSize && (buildings[idx][0] > rStack[stackSize - 1]))
        {
            height = (stackSize > 1) ? hStack[stackSize - 2] : 0;
            addItem2List(ret, returnSize, *returnColumnSizes, rStack[stackSize - 1], height);
            stackSize--;
        }

        if (buildings[idx][2] > height)
        {
            height = buildings[idx][2];
            addItem2List(ret, returnSize, *returnColumnSizes, buildings[idx][0], height);
        }
        addRight2Stack(hStack, rStack, &stackSize, buildings[idx][1], buildings[idx][2]);
    }

    while (stackSize)
    {
        height = (stackSize > 1) ? hStack[stackSize - 2] : 0;
        addItem2List(ret, returnSize, *returnColumnSizes, rStack[stackSize - 1], height);
        stackSize--;
    }

    return ret;
}
// @lc code=end

