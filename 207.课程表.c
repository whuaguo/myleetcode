/*
 * @lc app=leetcode.cn id=207 lang=c
 *
 * [207] 课程表
 */

// @lc code=start

int nextidx[5000] = {0};
int nextidxdone[5000] = {0};
int next[5000][100] = {0};
int nextSize[5000] = {0};
int nextidxSize = 0;

bool deepSearchAndMark(int val) {
    //取课程的配对集合
    int nextidxval = nextidx[val];

    //该课程已经正确结束，直接略过
    if (nextidxdone[val] == 2) {
        return true;
    }

    //该课程正在找尾过程中，死循环，退出
    if (nextidxdone[val] == 1) {
        return false;
    }

    nextidxdone[val] = 1;
    //一次从配对集合中取出，往下循环查找
    for (int i = 0; i < nextSize[nextidxval]; i++) {
        int nextval = next[nextidxval][i];

        //无配对集合，退出 
        if (nextidx[nextval] == -1) {
            continue;
        }

        if (!deepSearchAndMark(nextval)) {
            return false;
        }
    }

    //循环完毕，标记该课程无循环
    nextidxdone[val] = 2;

    return true;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    //无配对，肯定没问题
    if (prerequisitesSize == 0) {
        return true;
    }

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
            return false;
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

    //一次遍历所有课程value
    for (int idx = 0; idx < numCourses; idx++) {
        //无配对集合，skip
        if (nextidx[idx] == -1) {
            continue;
        }

        //有配对集合，循环查找是否有循环
        if (!deepSearchAndMark(idx)) {
            return false;
        }
    }

    return true;
}
// @lc code=end

