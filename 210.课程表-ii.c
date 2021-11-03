/*
 * @lc app=leetcode.cn id=210 lang=c
 *
 * [210] 课程表 II
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int nextidx[2000] = {0};
int nextidxdone[2000] = {0};
int next[2000][2000] = {0};
int nextSize[2000] = {0};
int nextidxSize = 0;
int stack[2000] = {0};
int stackSize = 0;

bool deepSearchAndMark(int val, int *localStack, int *localStackSize) {
    //取课程的配对集合
    int nextidxval = nextidx[val];

    //该课程已经正确结束，直接略过
    if (nextidxdone[val] == 2) {
        return true;
    }

    //该课程已经正确结束，直接略过
    if (nextidxdone[val] == 1) {
        return false;
    }

    nextidxdone[val] = 1;
    int totalSize = 0;
    int totalStack[2000] = {0};
    //一次从配对集合中取出，往下循环查找
    for (int i = 0; i < nextSize[nextidxval]; i++) {
        int nextval = next[nextidxval][i];
        int astack[2000];
        int astackSize = 0;

        //无配对集合，退出 
        if (nextidx[nextval] == -1 ){
            nextidx[nextval] = -2;
            memcpy(totalStack + (2000 - 1 - totalSize), &nextval, sizeof(int));
            totalSize += 1;
            continue;
        } else if (nextidx[nextval] == -2) {
            continue;
        }

        if (!deepSearchAndMark(nextval,astack, &astackSize)) {
            return false;
        }

        memcpy(totalStack + (2000 - astackSize - totalSize), astack, astackSize * sizeof(int));
        totalSize += astackSize;
    }

    localStack[0] = val;
    memcpy(localStack + 1, totalStack + 2000 - totalSize,sizeof(int) * totalSize);
    *localStackSize = totalSize + 1;

    //循环完毕，标记该课程无循环
    nextidxdone[val] = 2;

    return true;
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize){
    //课程value的配对集合idx
    memset(nextidx, -1, sizeof(int)*numCourses);
    
    //idx是否已经全部检查完毕, 0：没有查过，1：正在查，2：已经检查完毕
    memset(nextidxdone, 0, sizeof(int)*numCourses);
    
    //课程value对应的配对集合大小
    memset(nextSize, 0, sizeof(int)*numCourses);

    //初始无集合
    nextidxSize = 0;

    //遍历配对集合，把每个课程对应的配对放入集合
    for (int idx = 0; idx < prerequisitesSize; idx++) {
        int val = prerequisites[idx][1];
        int nextVal = prerequisites[idx][0];
        int nextidxval = nextidx[val]; 

        if (val == nextVal) {
            return NULL;
        }

        if (nextidxval == -1) {
            //无配对集合，那就加一个配对集合在尾部，记住配对idx
            nextidx[val] = nextidxSize;
            next[nextidxSize][nextSize[nextidxSize]] = nextVal;
            nextSize[nextidxSize] += 1;
            nextidxSize++;
        } else {
            //有配对集合，增加size，并记住配对idx
            next[nextidxval][nextSize[nextidxval]] = nextVal;
            nextSize[nextidxval] += 1;
        }
    }

    int totalSize = 0;
    int totalStack[2000] = {0};
    for (int idx = 0; idx < numCourses; idx++) {
        //无配对集合，skip
        if (nextidx[idx] == -1 || nextidx[idx] == -2) {
            continue;
        }

        int localStack[2000] = {0};
        int localStackSize = 0;
        //有配对集合，循环查找是否有循环
        if (!deepSearchAndMark(idx, localStack, &localStackSize)) {
            *returnSize = 0;
            return NULL;
        }

        memcpy(totalStack + (2000 - localStackSize - totalSize), localStack, localStackSize * sizeof(int));
        totalSize += localStackSize;
    }

    int *ret = malloc(numCourses * sizeof(int));
    int retSize = 0;
    assert(ret);
    *returnSize = numCourses;

    //一次遍历所有课程value
    for (int idx = 0; idx < numCourses; idx++) {
        //无配对集合，先学了
        if (nextidx[idx] == -1) {
            ret[retSize++] = idx;
        }
    }

    if (totalSize) {
        memcpy(ret+retSize, totalStack + 2000 - totalSize, totalSize*sizeof(int));
    }

    return ret;
}
// @lc code=end

