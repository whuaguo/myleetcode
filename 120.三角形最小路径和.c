/*
 * @lc app=leetcode.cn id=120 lang=c
 *
 * [120] 三角形最小路径和
 */

// @lc code=start


int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    if (triangle == NULL || triangleSize <= 0) {
        return 0;
    }

    int mins[200] = {0};

    //初始化最小值为底边的值
    for (int j = 0; j < triangleSize; j++) {
        mins[j] = triangle[triangleSize - 1][j];
    }

    for (int i = triangleSize - 2;i >=0; i--) {
        for (int j = 0; j < i + 1; j++) {
            //从底边依次向上求最小值
            mins[j] = triangle[i][j] + ((mins[j] < mins[j+1]) ? mins[j]:mins[j+1]);
        }
    }

    //返回顶点的值
    return mins[0];
}
// @lc code=end

