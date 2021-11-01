<<<<<<< HEAD
/*
 * @lc app=leetcode.cn id=188 lang=c
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start


int maxProfit(int k, int* prices, int pricesSize){
    if (pricesSize == 0 || k == 0) {
        return 0;
    }

    int b[100];
    int s[100];

    for (int idx = 0; idx < k; idx++) {
        b[idx] = 0 - prices[0];
        s[idx] = 0;
    }

    for (int i = 1; i < pricesSize; i++)  {
        for (int idx = 0; idx < k; idx ++) {
            int newb = ((idx == 0) ? 0 : s[idx - 1]) - prices[i];
            if (b[idx] < newb) {
                b[idx] = newb;
            }

            int news = b[idx] + prices[i];
            if (s[idx] < news) {
                s[idx] = news;
            }
        }
    }

    return s[k -1];
}
// @lc code=end

=======
/*
 * @lc app=leetcode.cn id=188 lang=c
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start


int maxProfit(int k, int* prices, int pricesSize){
    if (pricesSize == 0 || k == 0) {
        return 0;
    }

    int b[100];
    int s[100];

    for (int idx = 0; idx < k; idx++) {
        b[idx] = 0 - prices[0];
        s[idx] = 0;
    }

    for (int i = 1; i < pricesSize; i++)  {
        for (int idx = 0; idx < k; idx ++) {
            int newb = ((idx == 0) ? 0 : s[idx - 1]) - prices[i];
            if (b[idx] < newb) {
                b[idx] = newb;
            }

            int news = b[idx] + prices[i];
            if (s[idx] < news) {
                s[idx] = news;
            }
        }
    }

    return s[k -1];
}
// @lc code=end

>>>>>>> b9e17ed08f68eccf15d14565f758e023fbb7ed3d
