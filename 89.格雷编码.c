/*
 * @lc app=leetcode.cn id=89 lang=c
 *
 * [89] 格雷编码
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize){
    int *ret;
    int count = 1;

    *returnSize = 1 << n;
    ret = malloc(*returnSize * sizeof(int));
    if (NULL == ret) {
        return NULL;
    }

    ret[0] = 0;

    //n的格雷码前面n-1的格雷码，后面是n-1的格雷码反序中的每一个码|1<<n
    for (int i = 0; i < n; i ++) {
        int preCount = count;
        int base = count;
        while (preCount > 0) {
            ret[count++] = ret[--preCount] | base;
        }
    }

    return ret;
}
// @lc code=end

