/*
 * @lc app=leetcode.cn id=273 lang=c
 *
 * [273] 整数转换英文表示
 */

// @lc code=start

char num2str_small[20][20] = {
    "Zero",
    "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
    "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
char num2str_medium[10][20] = {
    "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
char num2str_large[4][20] = {
    "Billion",
    "Million",
    "Thousand",
    "",
};

void num2str(char *ret, int num)
{
    if (num >= 100)
    {
        strcat(ret, num2str_small[num / 100]);
        strcat(ret, " Hundred");
    }
    printf("ret: %s\n", ret);

    num = num % 100;
    if (num >= 20)
    {
        strcat(ret, " ");
        strcat(ret, num2str_medium[num / 10]);
        printf("ret: %s\n", ret);
        if (num % 10)
        {
            strcat(ret, " ");
            strcat(ret, num2str_small[num % 10]);
            printf("ret: %s\n", ret);
        }
    }
    else if (num)
    {
        strcat(ret, " ");
        strcat(ret, num2str_small[num]);
        printf("ret: %s\n", ret);
    }
}

char *numberToWords(int num)
{
    bool start = false;
    char *ret = malloc(sizeof(char) * 500);
    assert(ret != NULL);

    memset(ret, 0, 500);
    num2str(ret, num);

    return ret;
}
// @lc code=end
