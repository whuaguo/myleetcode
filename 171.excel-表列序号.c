/*
 * @lc app=leetcode.cn id=171 lang=c
 *
 * [171] Excel 表列序号
 */

// @lc code=start


int titleToNumber(char * columnTitle){
    int ret = 0;
    int len = strlen(columnTitle);

    for (int idx = 0; idx < len; idx++) {
        ret = ret * 26 + (columnTitle[idx] - 'A' + 1);
    }

    return ret;
}
// @lc code=end

