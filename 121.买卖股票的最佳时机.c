/*
 * @lc app=leetcode.cn id=121 lang=c
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start


int maxProfit(int* prices, int pricesSize){
    if (pricesSize <= 1) {
        return 0;
    }

    int maxProfit = 0;                  //从后往前算的最大利润
    int max = prices[pricesSize - 1];   //从后往前算的最高值

    //从最后一天往前算
    for (int i = pricesSize - 2; i >= 0; i--) {
        //如果当前值为起点的利润大于最大利润，更新最大利润
        if (maxProfit < (max - prices[i])){
            maxProfit = (max - prices[i]);
        }

        //如果当前值的后面的最大值不如当前值，更新最大值
        if (max < prices[i]) {
            max = prices[i];
        }
    }

    return maxProfit;
}
// @lc code=end

