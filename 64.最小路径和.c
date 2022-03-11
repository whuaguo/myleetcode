/*
 * @lc app=leetcode.cn id=64 lang=c
 *
 * [64] 最小路径和
 */

// @lc code=start


int minPathSum(int** grid, int gridSize, int* gridColSize){
    int dp[200][200];
    int i, j;
    for (i = 0; i < gridSize; i ++){
        for (j = 0; j < gridColSize[0]; j ++) {
            dp[i][j] = grid[i][j];
            if (i || j) {
                int up = (i > 0)? dp[i-1][j] : 0x7fffffff;
                int left = (j > 0)? dp[i][j-1] : 0x7fffffff;
                dp[i][j] += ((left > up)? up : left);
            }
        }
    }

    return dp[gridSize - 1][gridColSize[0]-1];
}
// @lc code=end

