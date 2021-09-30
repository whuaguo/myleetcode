/*
 * @lc app=leetcode.cn id=64 lang=c
 *
 * [64] 最小路径和
 */

// @lc code=start


int minPathSum(int** grid, int gridSize, int* gridColSize){
    int *dp;
    dp = malloc(sizeof(int) * gridSize * gridColSize[0]);
    if (dp == NULL) {
        return 0;
    }

    int i, j;
    int num = 0; 
    for (i = 0; i < gridSize; i ++){
        for (j = 0; j < gridColSize[0]; j ++) {
            int up;
            int left;

            dp[num] = grid[i][j];
            
            //非[0,0], 需要+min(up, left)
            if (i!=0 || j!=0) {
                up = (i > 0)? dp[num - gridColSize[0]] : 0x7fffffff;
                left = (j > 0)? dp[num -1] : 0x7fffffff;
                dp[num] += (left > up)? up : left;
            }
            num ++;
        }
    }

    //取得结果，释放内存
    int ret = dp[num -1];
    free(dp);

    return ret;
}
// @lc code=end

