/*
 * @lc app=leetcode.cn id=32 lang=c
 *
 * [32] 最长有效括号
 */

// @lc code=start

int longestValidParentheses(char * s){
    #define IS_LEFT(i)      (s[i] == '(')
    #define IS_RIGHT(i)     (s[i] == ')')

    short len = strlen(s);
    short max = 0;
    short top = -1;
    short *stack;

    if (len < 2) {
        return 0;
    }

    stack = malloc (sizeof(short) * (len+1));
    if (!stack) {
        return 0;
    }

    //栈底是有效字符串开始的起始index
    stack[++top] = -1;

    for (int i = 0; i < len; i++) {
        if (IS_LEFT(i)) {
            stack[++top] = i;
        } else {
            --top;

            if (top == -1) {
                //栈里没东西了，把当前index压入栈
                stack[++top] = i;
            } else {
                //计算当前index和栈顶位置的距离，取大值
                if (max < (i - stack[top])) {
                    max = i - stack[top];
                }
            }
        }
    }

    return max;
}
// @lc code=end

