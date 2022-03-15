/*
 * @lc app=leetcode.cn id=44 lang=c
 *
 * [44] 通配符匹配
 */

// @lc code=start

bool isMatchStar(char *s, char *p) {
    int slen = strlen(s);
    int plen = strlen(p);

    if (plen <= 2) return true;
    if (!slen) return false;
    //if ((plen - slen == 2)&&!memcmp(p+1, s, slen)) return true;

    bool dp[2000][2000] = {0};

    dp[0][0] = true;
    dp[0][1] = true;
    for (int i = 0; i < slen; i++) {
        dp[i][1] = true;
        
        for (int j = 1; j < plen; j++) {
            if (p[j] == '*') {
                dp[i+1][j+1] = (dp[i+1][j] || dp[i][j+1]); 
            } else {
                dp[i+1][j+1] = (dp[i][j]&& ((p[j]=='?') || (s[i] == p[j])));
            }
        }
    }

    return dp[slen][plen];
}

bool isMatch(char * s, char * p){
    char *ss = s;
    char *pp = p;

    while ((*pp != '*') && (*pp != '\0')) {
        if (*ss == '\0') {
            return false;
        }
        if ((*pp == '?') || (*pp == *ss)) {
            pp++;
            ss++;
        } else {
            return false;
        }
    }

    if (*pp == '*') {
        while ('*' == *(pp+1)) {
            pp++;
        }
    } else {
        return (*ss == '\0');
    }

    char *sss = s + strlen(s) - 1;
    char *ppp = p + strlen(p) - 1;

    while ((ppp > pp) && (*ppp != '*')) {
        if (sss < ss) {
            return false;
        }
        if ((*ppp == '?') || (*ppp == *sss)) {
            ppp--;
            sss--;
        } else {
            return false;
        }
    }

    if (*ppp == '*') {
        while ((ppp>pp)&&('*' == *(ppp-1))) {
            ppp--;
        }
    }

    *(ppp+1) = '\0';
    *(sss+1) = '\0';

    return isMatchStar(ss, pp);
}
// @lc code=end

