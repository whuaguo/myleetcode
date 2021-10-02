/*
 * @lc app=leetcode.cn id=76 lang=c
 *
 * [76] 最小覆盖子串
 */

// @lc code=start

#define SC(c)   sc[c - 'A']
#define TC(c)   tc[c - 'A']
#define SET_WIN if (wlen > rp -lp) {\
                    wlen = rp - lp; \
                    start = lp; \
                }

char * minWindow(char * s, char * t){
    short tc['z' - 'A' + 1] = {0};  //记录每个目录字符的个数    
    short sc['z' - 'A' + 1] = {0};  //滑动窗口内每个字符出现的个数
    short tcc = 0;                  //记录目标字符出现的个数
    short mtcc = 0;                 //滑动窗口内已满足目标字符串中字符的个数
    int lp = 0;                     //滑动窗口左边指针
    int rp = 0;                     //滑动窗口右边指针
    int start = 0;                  //满足条件的字符串开始位置
    int wlen = 0x7fffffff;          //满足条件的字符最小长度
    int slen = strlen(s);
    int tlen = strlen(t);

    //统计t中每个字符的个数
    for (int i = 0; i < tlen; i ++) {
        TC(t[i])++;
    }

    //统计t中总字符的个数
    for (char c = 'A'; c <= 'z'; c++) {
        if (TC(c) > 0) {
            tcc++;
        }
    }

    while (rp < slen) {
        char rc = s[rp++];
        
        if ((0 == TC(rc)) ||        /*无效字符*/ 
            (++SC(rc) != TC(rc)) || /*有效，但计数之后还不满足对应字符目标*/
            (++mtcc != tcc))        /*字符满足目标，但总目标不满足*/
        {    
            continue;
        }

        //满足条件了，记住起始地址，并记住当前的字符串长度
        SET_WIN;

        //开始移动左边指针，看看能否缩小范围
        for (;mtcc == tcc; lp++) {
            char lc = s[lp];

            if (TC(lc) && --SC(lc) < TC(lc)) {
                mtcc--;

                //不管是非有效字符，或有效字符但依然满足条件，判断长度
                SET_WIN;
            }
        }
    }

    if (wlen == 0x7fffffff) {
        wlen = 0;
    } 
    
    char * retstr = malloc(wlen + 1);
    if (NULL == retstr) {
        return NULL;
    }

    if (wlen > 0) {
        memcpy(retstr, s + start, wlen);
    }
    retstr[wlen] = 0;
        
    return retstr;
}
// @lc code=end

