/*
 * @lc app=leetcode.cn id=299 lang=c
 *
 * [299] 猜数字游戏
 */

// @lc code=start
int charCompare(const void *a, const void *b)
{
    return (*(char *)a - *(char *)b);
}
char *getHint(char *secret, char *guess)
{
    int countA = 0;
    int countB = 0;
    int slen = strlen(secret);
    int glen = strlen(guess);
    int len = (slen <= glen) ? slen : glen;
    char *str1 = malloc(slen + 1);
    char *str2 = malloc(glen + 1);
    assert(str1 != NULL);
    assert(str2 != NULL);

    memset(str1, 0, slen + 1);
    memset(str2, 0, glen + 1);
    int ne = 0;
    int idx;
    for (idx = 0; idx < len; idx++)
    {
        if (secret[idx] == guess[idx])
        {
            countA++;
        }
        else
        {
            str1[ne] = secret[idx];
            str2[ne++] = guess[idx];
        }
    }

    if (idx != slen)
    {
        memcpy(str1 + ne, secret + slen, slen - idx);
    }
    else
    {
        memcpy(str2 + ne, guess + glen, glen - idx);
    }

    qsort(str1, slen - countA, sizeof(char), charCompare);
    qsort(str2, glen - countA, sizeof(char), charCompare);

    char *s1 = str1;
    char *s2 = str2;
    while (*s1 && *s2)
    {
        if (*s1 == *s2)
        {
            s1++;
            s2++;
            countB++;
        }
        else if (*s1 < *s2)
        {
            s1++;
        }
        else
        {
            s2++;
        }
    }

    char *ret = malloc(11);
    assert(ret != NULL);
    sprintf(ret, "%dA%dB", countA, countB);

    free(str1);
    free(str2);
    return ret;
}
// @lc code=end
