/*
 * @lc app=leetcode.cn id=43 lang=c
 *
 * [43] 字符串相乘
 */

// @lc code=start


char * multiply(char * num1, char * num2){
    char table[10][10] = {
        "0000000000",
        "0123456789",
        "0246802468",
        "0369258147",
        "0482604826",
        "0505050505",
        "0628406284",
        "0741852963",
        "0864208642",
        "0187654321",
    }
    
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    char *ret = malloc(len1 + len2 + 1);
    assert(ret != NULL);
    memset(ret, 0, len1 + len2 + 1);

    for (int idx = len1 + len2 - 1; idx >= 0; idx--) {

    }

    return ret;
}
// @lc code=end

