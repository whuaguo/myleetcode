/*
 * @lc app=leetcode.cn id=7 lang=c
 *
 * [7] 整数反转
 */

// @lc code=start


int reverse(int x){
    int ax;
    int plus;
    int retx;

    //特例
    if (x== 0x80000000) {
        return 0;
    }

    if (x < 0 ) {
        ax = 0 - x;
        plus = 0;
    } else {
        plus = 1;
        ax = x;
    }

    retx = 0;
    while (ax){
        if (retx > (0x7fffffff / 10)){
           return 0; 
        } else {
            retx = retx * 10; 
            
            if (0x7fffffff - retx < ax % 10) {
                return 0;
            } else {
                retx += ax % 10;
            }

            ax = ax / 10;
        }
    }

    return plus?retx:(0-retx);
}
// @lc code=end

