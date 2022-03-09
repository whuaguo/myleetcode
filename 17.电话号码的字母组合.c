/*
 * @lc app=leetcode.cn id=17 lang=c
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){
    char table[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int len = strlen(digits);

    //check if the input digits string is NULL
    if (len == 0) {
        *returnSize = 0;
        return NULL;
    }

    //calculate total possibilities
    int total_num = 1;
    for (int i = 0; i < len; i++) {
        total_num = total_num * strlen(table[digits[i] - '0']);
    }

    //alloc the return array of string
    char **ret = malloc(total_num * sizeof(char *));
    assert(ret != NULL);
    for (int i = 0; i < total_num; i++) {
        ret[i] = malloc(len + 1);
        assert(ret[i] != NULL);
        ret[i][len] = '\0';
    }

    int block_size = total_num;
    for (int i = 0; i < len ; i++) {
        int cnum = strlen(table[digits[i] - '0']);
        int total_count = 0;
        int cidx = 0;

        block_size = block_size / cnum;
        while (total_count < total_num) {
            for (int bidx = 0; bidx < block_size; bidx++){
                ret[total_count++][i] = table[digits[i]- '0'][cidx];
            }

            if (++cidx == cnum) {
                cidx = 0;
            }
        }
    }

    *returnSize = total_num;
    return ret;
}
// @lc code=end

