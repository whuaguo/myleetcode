/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 */

// @lc code=start

bool is_paired(char a, char b) {
    return ((a == '(') && (b == ')') || 
            (a == '[') && (b == ']') ||
            (a == '{') && (b == '}'));
}

bool is_left(char a) {
    return (a=='(') || (a=='[') || (a=='{');
}

bool isValid(char * s){
    char stack[100001];
    int len = strlen(s);
    int stack_len = 0;

    //奇数长度，肯定false
    if (len & 1) {
        return false;
    }

    for (int i = 0; i < len; i++ ) {
        if (is_left(s[i])) {
            //入栈
            stack[stack_len++] = s[i];
        } else {
            //栈空，false
            if (stack_len == 0) {
                return false;
            }

            if (!is_paired(s[i], stack[stack_len - 1])) {
                stack_len --;
                return false;
            }
        }
    }

    if (stack_len != 0) {
        return false;
    }

    return true;
}
// @lc code=end

