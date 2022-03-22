/*
 * @lc app=leetcode.cn id=273 lang=c
 *
 * [273] 整数转换英文表示
 */

// @lc code=start

char num2str_small[20][10] = {
    "Zero",
    "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
    "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
char num2str_medium[10][10] = {
    "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
char num2str_large[4][10] = {
    "Billion",
    "Million",
    "Thousand",
    "",
};

#define appendStr(ret, str)   \
    {                         \
        if (strlen(ret))      \
        {                     \
            strcat(ret, " "); \
        }                     \
        strcat(ret, str);     \
    }

void num2str(char *ret, int num)
{
    if (num >= 100)
    {
        //百位
        appendStr(ret, num2str_small[num / 100]);
        appendStr(ret, "Hundred");
        num = num % 100;
    }

    if (num >= 20)
    {
        //十位
        appendStr(ret, num2str_medium[num / 10]);
        num = num % 10;
    }

    if (num)
    {
        //小于19直接
        appendStr(ret, num2str_small[num]);
    }
}

char *numberToWords(int num)
{
    bool start = false;
    char *ret = malloc(sizeof(char) * 500);
    assert(ret != NULL);
    memset(ret, 0, 500);

    if (!num)
    {
        strcat(ret, num2str_small[0]);
        return ret;
    }

    int base = 1000000000;
    int idx = 0;
    while (idx < 4)
    {
        int part = num / base;

        if (part)
        {
            num2str(ret, part);
            if (idx < 3)
            {
                appendStr(ret, num2str_large[idx]);
            }
        }

        num = num % base;
        base = base / 1000;
        idx++;
    }

    return ret;
}
// @lc code=end
