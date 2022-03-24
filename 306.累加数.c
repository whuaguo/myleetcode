/*
 * @lc app=leetcode.cn id=306 lang=c
 *
 * [306] 累加数
 */

// @lc code=start
long str2num(char *nums, int len)
{
    long ret = nums[0] - '0';

    if (!ret && (len != 1))
        return -1;

    for (int idx = 1; idx < len; idx++)
    {
        ret = ret * 10 + nums[idx] - '0';
    }

    return ret;
}

bool isNumsAdditive(char *nums, int len1, int len2)
{
    long sum;
    int len = strlen(nums);
    long num1 = str2num(nums, len1);
    long num2 = str2num(nums + len1, len2);
    long sumlen = len1 + len2;

    if (num2 < 0)
    {
        return false;
    }

    while (sumlen < len)
    {
        sum = num1 + num2;
        char sumstr[20] = {0};
        sprintf(sumstr, "%ld", sum);

        int sumstrlen = strlen(sumstr);
        if ((sumlen + sumstrlen > len) ||
            (memcmp(nums + sumlen, sumstr, sumstrlen)))
        {
            return false;
        }

        if (sumlen + sumstrlen == len)
        {
            return true;
        }
        num1 = num2;
        num2 = sum;
        sumlen += sumstrlen;
    }

    return false;
}

#define MAX(n1, n2) ((n1) > (n2) ? (n1) : (n2))
#define SUM(n1, n2) ((n1) + (n2))

bool isAdditiveNumber(char *num)
{
    int len = strlen(num);

    for (int len1 = 1; len1 <= (len >> 1); len1++)
    {
        for (int len2 = 1; MAX(len1, len2) + SUM(len1, len2) <= len; len2++)
        {
            if (isNumsAdditive(num, len1, len2))
            {
                return true;
            }
        }
    }

    return false;
}
// @lc code=end
