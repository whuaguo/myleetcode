/*
 * @lc app=leetcode.cn id=63 lang=c
 *
 * [63] 不同路径 II
 */

// @lc code=start

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    //[0,0]有障碍，无答案
    if (obstacleGrid[0][0]) {
        return 0;
    }

    int *dp;
    dp = malloc(sizeof(int) * obstacleGridSize * obstacleGridColSize[0]);
    if (dp == NULL) {
        return 0;
    }

    //站上[0,0]
    dp[0] = 1;
    int i, j;
    int num = 0; 
    for (i = 0; i < obstacleGridSize; i ++){
        for (j = 0; j < obstacleGridColSize[0]; j ++) {
            if (obstacleGrid[i][j]) {
                //有障碍，无解
                dp[num++] = 0;
            } else {
                //无障碍，求解
                if (i!=0 || j!=0) {
                    //非[0,0], dp[num] = dp[num -1] + dp[num - colsize];
                    dp[num] = (i > 0) ? dp[num - obstacleGridColSize[0]] : 0;
                    dp[num] += (j > 0) ? dp[num - 1] : 0;
                }
                num++;
            }
        }
    }

    //取得结果，释放内存
    int ret = dp[num -1];
    free(dp);

    return ret;
}
// @lc code=end

