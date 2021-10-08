/*
 * @lc app=leetcode.cn id=96 lang=c
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start


int numTrees(int n){
    int treeSize[20] = {1,1,2};

    if (n >= 3) {
        for (int i = 3; i <= n; i ++) {
            int total = 0;

            for (int j = 0; j < i; j ++) {
                total += treeSize[j]*treeSize[i-1-j];
            }

            treeSize[i] = total;
        }
    }

    return treeSize[n];
}
// @lc code=end

