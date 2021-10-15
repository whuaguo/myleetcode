/*
 * @lc app=leetcode.cn id=139 lang=c
 *
 * [139] 单词拆分
 */

// @lc code=start

//判断字符是否在字典内
bool isRangeInDict(char * s, int len, char ** wordDict, int wordDictSize) {
    for (int idx = 0; idx < wordDictSize; idx ++) {
        if ((len == strlen(wordDict[idx])) &&
            (0   == memcmp(s, wordDict[idx], len))) {
            return true;
        }
    }

    return false;
}

bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    int len = strlen(s);

    //长度为0，true
    if (len == 0) {
        return true;
    }

    // breakable[i]代表长度为i能否被切割成功
    bool * breakable = malloc(sizeof(bool) * (len + 1));
    assert(breakable);
    memset(breakable, 0, sizeof(bool) * (len+1));

    //长度为0能够切割
    breakable[0] = true;
    for (int i = 1; i <= len; i++) {
        //长度为i，只要长度为breakable[0...j...i-1]为true，并且s[j..i]在词典中就为true
        for (int j = 0; j < i; j++) {
            if (breakable[j] && isRangeInDict(s+j, i -j, wordDict,wordDictSize)) {
                breakable[i] = true;
                break;
            }
        }
    }

    return breakable[len];
}
// @lc code=end

