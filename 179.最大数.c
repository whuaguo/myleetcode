/*
 * @lc app=leetcode.cn id=179 lang=c
 *
 * [179] 最大数
 */

// @lc code=start
//#define log printf
int intStrCompare(const void *a, const void *b)
{
    char *pa = *(char **)a;
    char *pb = *(char **)b;
    int lena = strlen(pa);
    int lenb = strlen(pb);
    int idx1 = 0;
    int idx2 = 0;

    int total = 0;
    //比较ab vs ba
    while (total++ <= lena + lenb)
    {
        int delta = pb[idx2++] - pa[idx1++];

        if (delta)
        {
            //如果不相等，返回
            return delta;
        }

        if (idx1 == lena)
        {
            if (lena != lenb)
            {
                // a轮回到b
                pa = *(char **)b;
                idx1 = 0;
            }
            else
            {
                //长度相对，字符串相对，返回0
                return 0;
            }
        }
        else
        {
            if (idx2 == lenb)
            {
                // b轮回到a
                pb = *(char **)a;
                idx2 = 0;
            }
        }
    }

    // 123 vs 123123这样的情况，返回0
    return 0;
}

char *largestNumber(int *nums, int numsSize)
{
    char **numstrs = malloc(numsSize * sizeof(char *));
    assert(numstrs != NULL);
    bool allZero = true;

    for (int idx = 0; idx < numsSize; idx++)
    {
        if (nums[idx])
        {
            allZero = false;
        }

        numstrs[idx] = malloc(sizeof(char) * 11);
        assert(numstrs[idx] != NULL);
        sprintf(numstrs[idx], "%d", nums[idx]);
    }

    if (allZero)
    {
        return "0";
    }

    qsort(numstrs, numsSize, sizeof(char *), intStrCompare);

    char *ret = malloc(sizeof(char) * 100 * 10);
    assert(ret != NULL);
    memset(ret, 0, 100 * 10);

    for (int idx = 0; idx < numsSize; idx++)
    {
        strcat(ret, numstrs[idx]);
        free(numstrs[idx]);
    }

    free(numstrs);
    return ret;
}
// @lc code=end
