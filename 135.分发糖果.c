/*
 * @lc app=leetcode.cn id=135 lang=c
 *
 * [135] 分发糖果
 */

// @lc code=start


int candy(int* ratings, int ratingsSize){
    int *candys = malloc(sizeof(int) * ratingsSize);

    assert(candys);

    candys[0] = 1;
    for (int idx = 1; idx < ratingsSize; idx++) {
        if (ratings[idx] > ratings[idx - 1]) {
            candys[idx] = candys[idx - 1] + 1;
        } else {
            candys[idx] = 1;
        }
    }

    for (int idx = ratingsSize - 2; idx >= 0; idx--) {
        if ((ratings[idx] > ratings[idx + 1]) && 
            (candys[idx] <= candys[idx + 1])) {
            candys[idx] = candys[idx + 1] + 1;
        }
    }

    int sum = 0;

    for (int idx = 0; idx < ratingsSize; idx ++) {
        sum += candys[idx];
    }

    return sum;
}
// @lc code=end

