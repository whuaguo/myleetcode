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
    int count;
    int baseCount;

    count = 1 << n;
    *returnSize = count;
    ret = malloc(sizeof(int) * count);
    if (NULL == ret) {
        return NULL;
    }

    ret[0] = 0;
    if (n == 0) {
        return ret;
    }

    //n的格雷码前面n-1的格雷码，后面是n-1的格雷码反序中的每一个码|1<<n
    count  = 1;
    baseCount = 1;
    for (int i = 0; i < n; i ++) {
        int preCount = baseCount;
        while (preCount > 0) {
            ret[count++] = ret[--preCount] | baseCount;
        }

        baseCount = baseCount << 1;
    }

    return ret;
}
// @lc code=end

