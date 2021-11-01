/*
 * @lc app=leetcode.cn id=202 lang=c
 *
 * [202] 快乐数
 */

// @lc code=start

static inline int getHappyValue(int n) {
    int ret = 0;
    while (n) {
        int i = n % 10;
        ret += i * i;
        n = n / 10;
    }

    return ret;
}

bool isHappy(int n){
    char flag[200] = {0};

    while (1) {
        if (n == 1) {
            return true;
        }

        if (n < 200) {
            flag[n] = 1;
        }

        n = getHappyValue(n);
        if ((n < 200 ) && flag[n]) {
            return false;
        }
    }

    return false;
}
// @lc code=end

