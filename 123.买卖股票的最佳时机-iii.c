/*
 * @lc app=leetcode.cn id=123 lang=c
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start


int maxProfit(int* prices, int pricesSize){
    int b1 = -prices[0];
    int s1 = 0;
    int b2 = -prices[0];
    int s2 = 0;

    for (int i = 1; i < pricesSize; i++)  {
        //第一次买股票最大值
        int newb1 = 0 - prices[i];
        if (b1 < newb1) b1 = newb1;

        //第一次买卖之后的最大值
        int news1 = b1 + prices[i];
        if (s1 < news1) s1 = news1;

        //第二次买之后的最大值
        int newb2 = s1 - prices[i];
        if (b2 < newb2) b2 = newb2;

        //第二次买卖之后的最大值
        int news2 = b2 + prices[i];
        if (s2 < news2) s2 = news2;
    }

    return s2;
}
// @lc code=end

