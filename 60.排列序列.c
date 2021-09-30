/*
 * @lc app=leetcode.cn id=60 lang=c
 *
 * [60] 排列序列
 */

// @lc code=start

/*
 * 解题思路
 *  交换第n位和第n+1位，那么序列号往后移动的位数是1*2*3*..*n，
 *  那么先找到第一个n，是(n+1)！>k,但n！<=k, 交换n和n+1，
 *  然后k= k-n！。然后再找下一个n，知道k减到0
 *  
 *  交换n和n+1，不是简单的交换，是从n+1开始往后找一个比n大的数
 *  交换，否则第一次交换之后，第二次交换就又换回来了。
 */

char * getPermutation(int n, int k){
    int pn = 1;
    int kl = k - 1;
    char *ret;

    //初始化返回字符串
    ret = malloc(n + 1);
    if (ret == NULL) {
        return NULL;
    }

    memset(ret, 0, n + 1);
    for (int i = 1; i <= n; i++) {
        ret[i - 1] = '0' + i;
    }

    while (kl > 0) {
        int i;
        char buffer;

        //找到第一个需要交换位置的地方
        pn = 1;
        for (i = 1; i < n; i ++) {
            int pnn = pn * i;
            if (pnn > kl) {
                break;
            }
            pn = pnn;;
        }

        //减少pn
        kl -= pn;

        //从n-i+1开始，找到第一个比n-i大的数字
        int j = n - i + 1;
        while (ret[n - i] > ret[j]) {
            j ++;
        }

        //交换
        buffer = ret[j];
        ret[j] = ret[n-i];
        ret[n-i] = buffer;
    }

    return ret;
}
// @lc code=end

