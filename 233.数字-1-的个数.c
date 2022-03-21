/*
 * @lc app=leetcode.cn id=233 lang=c
 *
 * [233] 数字 1 的个数
 */

// @lc code=start

int countDigitOne(int n)
{
    /*
     * 对于第i位为是1的个数(1-代表个数，2代表10位，3代表100位...)
     * 比如 1   : n/10 * 1      个位1出现，n%10 >= 1, 为1, 否则 n%10 - 1 + 1
     *      2   : n/100 * 10    十位1出现，n%100 >= 10, 为10， 否则n%100 - 10 + 1
     *      3   : n/1000 * 100  百位1出现，n%/1000 >= 100, 为100，否则n%1000 - 100 + 1；
     *      i   : n/10^i * 10^i i位1出现,  n%10^(i+1) >= 10^i, 为10^(i-1),n%10^i - 10^(i-1) +1;
     */
    int total = 0;
    for (long i = 1; i <= n; i *= 10)
    {
        long teni = 10 * (long)i;
        total += (n / teni) * i;

        int rem = n % teni;

        if (rem < i)
        {
            rem = 0;
        }
        else if (rem < (i << 1))
        {
            rem += 1 - i;
        }
        else
        {
            rem = i;
        }

        total += rem;
    }

    return total;
}
// @lc code=end
