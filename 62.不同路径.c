/*
 * @lc app=leetcode.cn id=62 lang=c
 *
 * [62] 不同路径
 */

// @lc code=start


int uniquePaths(int m, int n){
    int *dp;
    dp = malloc(sizeof(int) * m *n);
    if (dp == NULL) {
        return 0;
    }

    //站上[0,0]
    dp[0] = 1;
    int i, j;
    int num = 0; 
    for (i = 0; i < m; i ++){
        for (j = 0; j < n; j ++) {
            //无障碍，求解
            if (i!=0 || j!=0) {
                //非[0,0], dp[num] = dp[num -1] + dp[num - colsize];
                dp[num] = (i > 0) ? dp[num - n] : 0;
                dp[num] += (j > 0) ? dp[num - 1] : 0;
            }
            num++;
        }
    }

    //取得结果，释放内存
    int ret = dp[num -1];
    free(dp);

    return ret;
}
// @lc code=end

