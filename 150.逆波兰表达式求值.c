/*
 * @lc app=leetcode.cn id=150 lang=c
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start


#define MATH_ADD 1001
#define MATH_SUB 1002
#define MATH_MUL 1003
#define MATH_DIV 1004

#define IS_MATHSYM(x)   (x > 1000)
#define IS_ADD(x)       (x == MATH_ADD)
#define IS_SUB(x)       (x == MATH_SUB)
#define IS_MUL(x)       (x == MATH_MUL)
#define IS_DIV(x)       (x == MATH_DIV)

int evalRPN(char ** tokens, int tokensSize){
    int val[5000];      //栈空间
    int lastidx = -1;    //栈指针

    for (int idx = 0; idx < tokensSize; idx++) {
        if (tokens[idx][0] == '+') {
            //把栈的头部两个数字进行运算并压入栈
            val[lastidx - 1] += val[lastidx];
            lastidx--;
        } else if (tokens[idx][0] == '-') {
            if (1 == strlen(tokens[idx])) {
                //把栈的头部两个数字进行运算并压入栈
                val[lastidx - 1] -= val[lastidx];
                lastidx--;
            } else {
                //是数字，存放栈顶
                val[++lastidx] = 0 - atoi(tokens[idx] + 1);
            }
        } else if (tokens[idx][0] == '*') {
            //把栈的头部两个数字进行运算并压入栈
            val[lastidx - 1] *= val[lastidx];
            lastidx--;
        } else if (tokens[idx][0] == '/') {
            //把栈的头部两个数字进行运算并压入栈
            val[lastidx - 1] /= val[lastidx];
            lastidx--;
        } else {
            //是数字，存放栈顶
            val[++lastidx] = atoi(tokens[idx]);
        }
    }

    return val[0];
}
// @lc code=end

