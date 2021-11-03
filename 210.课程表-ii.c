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
int next[2000][100] = {0};
int nextSize[2000] = {0};
int nextidxSize = 0;

#define NON_PRE_INIT        -1
#define NON_PRE_TOUCHED     -2
#define LOOP_IN             1
#define LOOP_DONE           2
#define LOOP_NOT_START      0

bool deepSearchAndMark(int val, int *localStack, int *localStackSize) {
    //取课程的配对集合
    int nextidxval = nextidx[val];

    //该课程已经正确结束，直接略过
    if (nextidxdone[val] == LOOP_DONE) {
        return true;
    }

    //该课程正在循环中，loop，返回错误
    if (nextidxdone[val] == LOOP_IN) {
        return false;
    }

    nextidxdone[val] = LOOP_IN;
    int totalSize = 0;
    int totalStack[2000] = {0};
    //依次从配对集合中取出，往下循环查找
    for (int i = 0; i < nextSize[nextidxval]; i++) {
        //每次子序列都要放在前面
        int nextval = next[nextidxval][i];

        //无配对集合，退出 
        if (nextidx[nextval] == NON_PRE_INIT ){
            nextidx[nextval] = NON_PRE_TOUCHED;
            memcpy(totalStack + (2000 - 1 - totalSize), &nextval, sizeof(int));
            totalSize += 1;
            continue;
        } else if (nextidx[nextval] != NON_PRE_TOUCHED) {
            int astack[2000];
            int astackSize = 0;

            if (!deepSearchAndMark(nextval,astack, &astackSize)) {
                return false;
            }

            memcpy(totalStack + (2000 - astackSize - totalSize), astack, astackSize * sizeof(int));
            totalSize += astackSize;
        }
    }

    localStack[0] = val;
    memcpy(localStack + 1, totalStack + 2000 - totalSize,sizeof(int) * totalSize);
    *localStackSize = totalSize + 1;

    //循环完毕，标记该课程无循环
    nextidxdone[val] = LOOP_DONE;

    return true;
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize){
    //初始化全局变量
    memset(nextidx, NON_PRE_INIT, sizeof(int)*numCourses);
    memset(nextidxdone, LOOP_NOT_START, sizeof(int)*numCourses);
    memset(nextSize, 0, sizeof(int)*numCourses);

    //初始无集合
    nextidxSize = 0;

    //遍历配对集合，把每个课程对应的配对放入集合
    for (int idx = 0; idx < prerequisitesSize; idx++) {
        int val = prerequisites[idx][1];
        int nextVal = prerequisites[idx][0];
        int nextidxval = nextidx[val]; 

        if (nextidxval == NON_PRE_INIT) {
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

    int *totalStack = malloc(numCourses * sizeof(int));
    assert(totalStack);
    *returnSize = numCourses;

    int totalSize = 0;
    for (int idx = 0; idx < numCourses; idx++) {
        if (nextidx[idx] >= 0) {
            int localStack[2000] = {0};
            int localStackSize = 0;

            //有配对集合，循环查找是否有循环
            if (!deepSearchAndMark(idx, localStack, &localStackSize)) {
                *returnSize = 0;
                return NULL;
            }

            memcpy(totalStack + (numCourses - localStackSize - totalSize), localStack, localStackSize * sizeof(int));
            totalSize += localStackSize;
        }
    }

    totalSize = 0;
    //一次遍历所有课程value
    for (int idx = 0; idx < numCourses; idx++) {
        //无配对集合，先学了
        if (nextidx[idx] == NON_PRE_INIT) {
            totalStack[totalSize++] = idx;
        }
    }

    return totalStack;
}
// @lc code=end

