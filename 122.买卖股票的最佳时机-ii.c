/*
 * @lc app=leetcode.cn id=122 lang=c
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start


int maxProfit(int* prices, int pricesSize){
    if (pricesSize <= 1) {
        return 0;
    }

    int startIdx = 0;
    int endIdx = -1;
    int total = 0;

    for (int idx = 1; idx < pricesSize; idx++) {
        if (prices[idx] > prices[idx - 1]) {
            endIdx = idx;
        } else {
            if (endIdx > 0) {
                total += prices[endIdx] - prices[startIdx];
            }
            startIdx = idx;
            endIdx = -1;
        }
    }

    if (endIdx > 0) {
        total += prices[endIdx] - prices[startIdx];
    }

    return total;
}
// @lc code=end

