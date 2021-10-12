/*
 * @lc app=leetcode.cn id=127 lang=c
 *
 * [127] 单词接龙
 */

// @lc code=start

//判断两个字符串是否只有一个字符不同
int strDiffs(char * s1, char * s2) {
    int len = strlen(s1);

    if (len != strlen(s2)) {
        return 2;
    }

    int diffs = 0;
    for (int i = 0; i < len; i++) {
        if (s1[i] != s2[i]) {
            if (diffs++) {
                return 2;
            }
        } 
    }

    return diffs;
}

int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
    int dis[6000] = {0};
    int idxs1[6000] = {0};
    int idxs2[6000] = {0};
    int *idxs = idxs1;
    int *expandIdxs = idxs2;
    int idxsCount = 0;
    bool endInList = false;
    int depth = 0;

    for (int i = 0; i < wordListSize; i++) {
        int diffs = strDiffs(endWord, wordList[i]);
        if (1 == diffs ) {
            dis[i] = 1;
            idxs[idxsCount++] = i;
        } else if (0 == diffs) {
            endInList = true;
            dis[i] = 1;
        }
    }

    if (!endInList) {
        return 0;
    } 

    if (1 == strDiffs(beginWord, endWord)) {
        return 2;
    }

    depth = 1;
    while (idxsCount) {
        int sidx;
        int expandCount = 0;
        depth++;
        
        for (int idx = 0; idx < idxsCount; idx++) {
            sidx = idxs[idx];

            if (1 == strDiffs(wordList[sidx], beginWord)) {
                return depth + 1;
            }

            for (int i = 0; i < wordListSize; i++) {
                if (dis[i]) {
                    continue;
                } 

                if (1 == strDiffs(wordList[sidx], wordList[i])) {
                    dis[i] = depth;
                    expandIdxs[expandCount++] = i;
                }
            }
        }

        idxsCount = expandCount;
        int *buffer = idxs;
        idxs = expandIdxs;
        expandIdxs = buffer;
    }

    return 0;
}
// @lc code=end

