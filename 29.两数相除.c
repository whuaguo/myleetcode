/*
 * @lc app=leetcode.cn id=29 lang=c
 *
 * [29] 两数相除
 */

// @lc code=start


int divide(int dividend, int divisor){
    int div;
    int vis;
    bool is_minus;
    int ret = 0;

    if (divisor == 0) {
        return 0;
    }

    if (divisor == 1) {
        return dividend;
    }

    if (divisor == -1) {
        return (dividend == 0x80000000)?0x7fffffff:(0-dividend);
    }

    //divisor == 0x80000000 特殊处理
    if (divisor == 0x80000000) { 
        if (dividend == 0x80000000) {
            return 1;
        } else {
            return 0;
        }
    }

    //分母绝对值比分子大，直接返回0
    if ((dividend > 0) && (divisor > dividend || (0-divisor) > dividend) ||
        (dividend < 0) && (divisor < dividend || (0-divisor) < dividend)) {
        return 0;
    }

    vis = (divisor > 0)? divisor : (0 - divisor);
    div = (dividend > 0 )? dividend : ((dividend == 0x80000000) ? 0x7fffffff: (0 - dividend));
    is_minus = (dividend < 0) && (divisor >0) || (dividend > 0) && (divisor <0);

    while (div >= vis) {
        int div2 = div;
        int ret2 = 0;
        while (div2 >= vis) {
            div2 = div2 >> 1;
            ret2 ++ ;
        }
        ret += 1 << (ret2 - 1) ;
        div -= vis << (ret2 - 1);
    }

    //如果dividend是0x80000000，divisor是2的幂，前面变正0x7fffffff就造成商少1，必须+1
    if ((dividend == 0x80000000) && !(vis & (vis-1))) {
        ret ++;
    }

    return is_minus ? (0 - ret) : ret;
}
// @lc code=end

