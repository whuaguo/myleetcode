/*
 * @lc app=leetcode.cn id=12 lang=c
 *
 * [12] 整数转罗马数字
 */

// @lc code=start


char * intToRoman(int num){
    char digit2char[4][2] = {"IV", "XL", "CD", "MA"} ;
    int digit[4] = {0};

    char *ret = malloc(20);
    assert(ret != NULL);
    memset(ret, 0, 20);

    int idx = 0;
    while (num > 0) {
        digit[idx++] = num % 10;
        num = num / 10;
    }

    int charidx = 0;
    for (idx = 3; idx >= 0; idx --) {
        int num = digit[idx];
        if (!num) {
            continue;
        }

        char a = digit2char[idx][0];
        char b = digit2char[idx][1];

        if (num <= 3) {
            for (int i = 0; i < num; i++) {
                ret[charidx++] = a;
            }
        } else if (num == 4) {
            ret[charidx++] = a;
            ret[charidx++] = b;
        } else if (num < 9) {
            ret[charidx++] = b;
            for (int i = num; i > 5; i--) {
                ret[charidx++] = a;
            }
        } else {
            ret[charidx++] = a;
            ret[charidx++] = digit2char[idx+1][0];
        }
    }

    return ret;
}
// @lc code=end

