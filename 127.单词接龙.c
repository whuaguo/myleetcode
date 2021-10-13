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
    int nextToEnd[5000] = {[0...4999] = -1 };
    int idxs1[1000] = {0};
    int idxs2[1000] = {0};
    int *idxs = idxs1;
    int *expandIdxs = idxs2;
    int idxsCount = 0;
    int depth = 0;

    //nextToEnd[],里面存放wordList里面向endword变化的下一个变种
    //设定endword放在wordList[wordListSize]，beginword的下一个变种可放在一个全局变量。
    for (int idx = 0; idx < wordListSize; idx++) {
        int diffs = strDiffs(endWord, wordList[idx]);
        if (1 == diffs ) {
            nextToEnd[idx] = wordListSize; 
            idxs[idxsCount++] = idx;
        } else if (0 == diffs) {
            nextToEnd[idx] = -1; //-1代表就是终点endword
            nextToEnd[wordListSize] = idx;
        }
    }

    if (!nextToEnd[wordListSize]) {
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
                if (nextToEnd[i]) {
                    continue;
                } 

                if (1 == strDiffs(wordList[sidx], wordList[i])) {
                    nextToEnd[i] = sidx;
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

