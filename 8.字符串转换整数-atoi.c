/*
 * @lc app=leetcode.cn id=8 lang=c
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start


int myAtoi(char * s){
    int plus = 1;
    int cnum = 0; 
    int ret = 0;

    if (!strlen(s)) {
        return 0;
    }

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == ' ') {
            if (cnum) {
                return plus?ret:(0-ret);
            }

            //空格，直接忽略继续
            continue;
        } else if (s[i]=='+'){
            //+, 如果是必须数字，或数字+空格， 返回错误
            if (cnum) {
                return plus?ret:(0-ret);
            }

            cnum = 1;
            continue;
        } else if (s[i] == '-') {
            //+, 如果是必须数字，或数字+空格， 返回错误
            if (cnum) {
                return plus?ret:(0-ret);
            }

            cnum = 1;
            plus = 0;
            continue;
        } else if ((s[i]>= '0') && (s[i]<='9')) {
            //必须连续数字
            cnum = 1;

            if (ret > 0x7fffffff / 10 ) {
                if (plus == 0) {
                    return 0x80000000;
                } else {
                    return 0x7fffffff;
                }
            }

            int num = s[i] - '0';

            ret = ret * 10 ;
            if (num <= (0x7fffffff - ret) ) {
                ret += num;
            } else {
                if (plus == 0) {
                    return 0X80000000;
                } else {
                    return 0x7fffffff;
                }
            }
        } else {
            if (cnum) {
                return plus?ret:(0-ret);
            } else {
                return 0;
            }
        }
    }

    return plus?ret:(0-ret);
}
// @lc code=end

