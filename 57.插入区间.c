/*
 * @lc app=leetcode.cn id=57 lang=c
 *
 * [57] 插入区间
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    int **ret = malloc(sizeof(int *)*(intervalsSize + 1));
    *returnColumnSizes = malloc(sizeof(int) *(intervalsSize + 1));
    assert(ret != NULL);
    assert(*returnColumnSizes != NULL);

    int idx;
    int retidx = 0;
    int left, right;
    bool inserted = false;
    for (idx = 0; idx < intervalsSize; idx++) {
        //newInterval完全在ret[idx]前面
        if (intervals[idx][0] > newInterval[1]) {
            //把newinterval加到ret里面去,后面全添加
            ret[retidx] = newInterval;
            (*returnColumnSizes)[retidx++] = 2;
            inserted = true;
            break;
        } 

        //newInterval完全在ret[idx]后面
        if (intervals[idx][1] < newInterval[0]) {
            //把intervals[idx]加到ret里面去，后面继续
            ret[retidx] = intervals[idx];
            (*returnColumnSizes)[retidx++] = 2;
            continue;
        }   
        
        //有交叉，起始地址可以确定，终结地址需要往下寻找
        left  = (newInterval[0] < intervals[idx][0]) ? newInterval[0]:intervals[idx][0];
        right = (newInterval[1] > intervals[idx][1]) ? newInterval[1]:intervals[idx][1];

        int ridx = idx + 1;
        while ((ridx < intervalsSize) && (intervals[ridx][0] <= right)) {
            if (intervals[ridx][1] > right) {
                right = intervals[ridx][1];
            }
            ridx++;
        }

        //把新的interval添加到返回数组里面去        
        ret[retidx] = malloc(sizeof(int) * 2);
        assert(ret[retidx] != NULL);
        ret[retidx][0] = left;
        ret[retidx][1] = right;
        (*returnColumnSizes)[retidx++] = 2;
        idx = ridx;
        inserted = true;
        break;
    }

    if (!inserted) {
        //新的interval没有入队列,代表比所有已存interval都大，添加
        ret[retidx] = newInterval;
        (*returnColumnSizes)[retidx++] = 2;
    } else {
        //newInterval已经加入队列，需要把还没有遍历的intervals也添加到返回队列
        for (;idx < intervalsSize; idx++) {
            ret[retidx] = intervals[idx];
            (*returnColumnSizes)[retidx++] = 2;
        }
    }

    *returnSize = retidx;
    return ret;
}
// @lc code=end

