/*
 * @lc app=leetcode.cn id=218 lang=c
 *
 * [218] 天际线问题
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** getSkyline(int** buildings, int buildingsSize, int* buildingsColSize, int* returnSize, int** returnColumnSizes){
    int lStack[20000] = {0};
    int rStack[20000] = {0};
    int lStackSize = 0; //左边边界已经排序，用堆栈即可
    int rStackSize = 0; //右边边界乱序，用小顶堆

    int skyLines[20000][2] = {0};
    int skyLinesSize = 0;

    for (int idx = 0; idx < buildingsSize; idx++) {
        

    }

}
// @lc code=end

