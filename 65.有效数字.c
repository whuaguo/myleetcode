/*
 * @lc app=leetcode.cn id=65 lang=c
 *
 * [65] 有效数字
 */

// @lc code=start
#define is_digit(c)     (c >= '0' && c <= '9')
#define is_sign(c)      (c == '+' || c == '-')
#define is_blank(c)     (c == ' ')

bool isNumber(char * s){
    bool success = false; // 最开始匹配失败
    int k = 0;

    //1.撇开空格
    while (is_blank(s[k])) {
        k++;
    }

    //2.开始可以有+-，没有也没关系
    if is_sign(s[k]) {
        //过滤+|- 
        k++; 
    }

    //3.必须开始有数字，否则就错误
    while (is_digit(s[k])) {
        // 不管前面是否有符号+|-，一旦有数字，至此一定是匹配成功的
        k++;
        success = true; 
    }

    //4.可以有.
    if (s[k] == '.') {
        k++; 
    }

    //5.小数点后面必须是数字
    while (is_digit(s[k])) {
        k++;
        success = true;
    } 
    
    //如果没整数，或小数，直接返回错误。
    if (!success) { 
        return false;
    } 

    // 下面判断是否有指数
    if (s[k] == 'e' || s[k] == 'E') 
    {
        k++;
        
        //可以有+-
        if (is_sign(s[k])) { 
            k++; 
        }

        //必须有数字
        success = false; 
        while (is_digit(s[k])) {
            k++;
            success = true; 
        }
    }

    // 如何没有匹配到结尾了，说明是不合法数字
    if (k < strlen(s)) {
        return false;
    }

    // 如果到了最后一位，看是否匹配成功
    return success;
}
// @lc code=end

