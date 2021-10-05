/*
 * @lc app=leetcode.cn id=84 lang=c
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start


int largestRectangleArea(int* heights, int heightsSize){
    int lLessIdx[100000];
    int rLessIdx[100000];

    // 记录每个柱子 左边第一个小于该柱子的下标
    lLessIdx[0] = -1; // 注意这里初始化，防止下面while死循环
    for (int i = 1; i < heightsSize; i++) {
        int t = i - 1;
        
        // 这里不是用if，而是不断向左寻找的过程
        while (t >= 0 && heights[t] >= heights[i]) {
            t = lLessIdx[t];
        }

        lLessIdx[i] = t;
    }

    // 记录每个柱子 右边第一个小于该柱子的下标
    rLessIdx[heightsSize - 1] = heightsSize; // 注意这里初始化，防止下面while死循环
    for (int i = heightsSize - 2; i >= 0; i--) {
        int t = i + 1;
        
        // 这里不是用if，而是不断向右寻找的过程
        while (t < heightsSize && heights[t] >= heights[i]) {
            t = rLessIdx[t];
        }

        rLessIdx[i] = t;
    }

    // 求和
    int result = 0;
    for (int i = 0; i < heightsSize; i++) {
        int sum = heights[i] * (rLessIdx[i] - lLessIdx[i] - 1);
        result = (sum>result)?sum:result;
    }

    return result;
}
// @lc code=end

