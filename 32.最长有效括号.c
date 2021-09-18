/*
 * @lc app=leetcode.cn id=32 lang=c
 *
 * [32] 最长有效括号
 */

// @lc code=start

#define IS_LEFT(i)      (s[i] == '(')
#define IS_RIGHT(i)     (s[i] == ')')

int longestValidParentheses(char * s){
    short len = strlen(s);
    short stack_idx = 0;
    short *pstack;
    short *pleft_idx;

    if (len < 2) {
        return 0;
    }

    pstack = malloc (sizeof(short) * len);
    if (pstack == NULL) {
        return 0;
    }

    pleft_idx = malloc (sizeof(short) * len);
    if (pleft_idx == NULL) {
        free(pstack);
        return 0;
    }

    short rmlen = 0;

    for (short idx = 0; idx <= len; idx ++) {
        if ((idx == len) ||
            IS_LEFT(idx) ||  
            IS_RIGHT(idx) && (stack_idx == 0)) 
        {
            //3种情况需要算一下是否有了最长匹配
            //1. 左括号但右边是右括号
            //2. 字符串结尾
            //3. 右括号，但前面没有对应的左括号
            if (idx < len) {
                if (IS_LEFT(idx)) {
                    //把 idx 压栈，对应的右括号可以直接取这个idx计算长度
                    pstack[stack_idx++] = idx; 
                }
            }

            //不管是'('或')'但value==-1或结束，都代表一段完整括号的的结束，往后算一算长度
            if ((idx > 1) && (pleft_idx[idx - 1] > 0)) {
                //往后找一个有配对的')’，算idx，和前面一个和他匹配的'('的idx之间的差
                short zlen = idx - pleft_idx[idx -1] + 1;
                if (rmlen < zlen) {
                    rmlen = zlen;
                }
            }
        } else {
            int left_idx;

            if (stack_idx > 0) {
                //出栈
                stack_idx --;
            }

            //从栈的头部取出压栈的序列号
            left_idx = pstack[stack_idx];

            //前面没有合法的配对了，直接计入pleft_idx
            if ((left_idx > 1) && (pleft_idx[left_idx - 1] > 0)) {
                //如果当前序列号前一个字符也是')'，而且它有对应的'(',直接取它对应'('对应的序列号
                pleft_idx[idx] = pleft_idx[left_idx - 1];
            } else {
                //记录当前')'对应'('的序列号(+1)
                //+1可以区分pleft_idx里面存储的是一个有效的值，那些没有'('对应的存默认值0
                pleft_idx[idx] = left_idx + 1;
            }
        }
    }

    free(pstack);
    free(pleft_idx);
    return rmlen;
}
// @lc code=end

