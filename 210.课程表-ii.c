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

bool deepSearchAndMark(int val, int *stack, int *stackSize) {
    //取课程的配对集合
    int nextidxval = nextidx[val];

    switch (nextidxdone[val]){
        case LOOP_DONE:
            //该课程已经正确结束，直接略过
            return true;

        case LOOP_IN:
            //该课程正在循环中，loop，返回错误
            return false;
    }

    nextidxdone[val] = LOOP_IN;
    //依次从配对集合中取出，往下循环查找
    for (int i = 0; i < nextSize[nextidxval]; i++) {
        //每次子序列都要放在前面
        int nextval = next[nextidxval][i];

        //无配对集合，退出 
        if (nextidx[nextval] == NON_PRE_INIT ){
            //没有前置课程了，直接把课程压入栈
            nextidx[nextval] = NON_PRE_TOUCHED;
            *stackSize -= 1;
            stack[*stackSize] = nextval;
            continue;
        } else if (nextidx[nextval] != NON_PRE_TOUCHED) {
            //继续深度搜索
            if (!deepSearchAndMark(nextval,stack, stackSize)) {
                return false;
            }
        }
    }

    //把课程压入栈
    *stackSize -= 1;
    stack[*stackSize] = val;

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

    //分配出返回的课程列表
    int *stack = malloc(numCourses * sizeof(int));
    int stackSize = numCourses;
    assert(stack);

    for (int idx = 0; idx < numCourses; idx++) {
        if (nextidx[idx] >= 0) {
            //有配对集合，深度搜索
            if (!deepSearchAndMark(idx, stack, &stackSize)) {
                *returnSize = 0;
                return NULL;
            }
        }
    }

    //依次遍历所有课程value，找到孤立的课程，加到返回列表中
    for (int idx = 0; idx < numCourses; idx++) {
        //无配对集合，先学了
        if (nextidx[idx] == NON_PRE_INIT) {
            stack[--stackSize] = idx;
        }
    }

    *returnSize = numCourses;
    return stack;
}

// @lc code=end

