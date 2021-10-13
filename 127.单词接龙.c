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

#define INVALID_IDX     (-1)
#define TARGET_IDX      (wordListSize)
#define BEGIN_IDX       (wordListSize + 1)
#define END_IDX         (wordListSize + 2)
#define idx2word(idx)    ((idx == END_IDX) ? endWord : ((idx == BEGIN_IDX)? beginWord:wordList[idx]))

int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
#if 1
    short nextToEnd[5000] = {0};
    short nextToStart[5000] = {0};

    short idxs1[1000] = {0};
    short idxs2[1000] = {0};
    short idxs3[1000] = {0};

    short *eidxs = idxs1;
    short *sidxs = idxs2;
    short *expandIdxs = idxs3;
    short eidxsCount = 1;
    short sidxsCount = 1;
    short expandIdxsCount;

    short edepth = 0;
    short sdepth = 0;

    //判断endword是否在wordList中
    int idx;
    for (idx = 0; idx < wordListSize; idx++) {
        if (strDiffs(wordList[idx], endWord) == 0) {
            break;
        }
    }

    if (idx == wordListSize) {
        return 0;
    }

    memset(nextToEnd, INVALID_IDX, 5000*sizeof(short));
    memset(nextToStart, INVALID_IDX, 5000*sizeof(short));

    eidxs[0] = END_IDX;
    sidxs[0] = BEGIN_IDX;

    while (eidxsCount||sidxsCount) {
        bool    is2end = (eidxsCount <= sidxsCount); 
        short   idxsCount = is2end ? eidxsCount: sidxsCount;
        short*  idxs = is2end ? eidxs : sidxs;
        short*  paths = is2end ? nextToEnd : nextToStart;
        short*  rpaths = is2end ? nextToStart: nextToEnd;

        if (is2end) {
            edepth++;
        } else {
            sdepth++;
        }

        int expandCount = 0;
        for (int idx = 0; idx < idxsCount; idx++) {
            char *targetWord = idx2word(idxs[idx]);

            for (int i = 0; i < wordListSize; i++) {
                if (INVALID_IDX != paths[i]) {
                    continue;
                } 

                if (1 == strDiffs(targetWord, wordList[i])) {
                    paths[i] = idxs[idx];
                    expandIdxs[expandCount++] = i;
                    if (INVALID_IDX != rpaths[i]) {
                        //meet
                        return edepth + sdepth + 1;
                    }
                }
            }
        }

        short *buffer = expandIdxs;
        if (is2end) {
            eidxsCount = expandCount;
            expandIdxs = eidxs;
            eidxs = buffer;
        } else {
            sidxsCount = expandCount;
            expandIdxs = sidxs;
            sidxs = buffer;
        }
    }

    return 0;
#else
    short nextToEnd[5000] = {0};
    short idxs1[1000] = {0};
    short idxs2[1000] = {0};
    short *idxs = idxs1;
    short *expandIdxs = idxs2;
    short idxsCount = 0;
    short edepth = 0;

    memset(nextToEnd, INVALID_IDX, 5000*sizeof(short));

    //nextToEnd[],里面存放wordList里面向endword变化的下一个变种
    //设定endword放在wordList[wordListSize]，beginword的下一个变种可放在一个全局变量。
    for (int idx = 0; idx < wordListSize; idx++) {
        int diffs = strDiffs(endWord, wordList[idx]);
        if (1 == diffs ) {
            nextToEnd[idx] = END_IDX; 
            idxs[idxsCount++] = idx;
        } else if (0 == diffs) {
            nextToEnd[idx] = TARGET_IDX;
            nextToEnd[TARGET_IDX] = idx;
        }
    }

    if (INVALID_IDX == nextToEnd[TARGET_IDX]) {
        return 0;
    } 

    if (1 == strDiffs(beginWord, endWord)) {
        return 2;
    }

    edepth = 2;
    while (idxsCount) {
        int sidx;
        int expandCount = 0;
        edepth++;
        
        for (int idx = 0; idx < idxsCount; idx++) {
            sidx = idxs[idx];

            if (1 == strDiffs(wordList[sidx], beginWord)) {
                return edepth;
            }

            for (int i = 0; i < wordListSize; i++) {
                if (INVALID_IDX != nextToEnd[i]) {
                    continue;
                } 

                if (1 == strDiffs(wordList[sidx], wordList[i])) {
                    nextToEnd[i] = sidx;
                    expandIdxs[expandCount++] = i;
                }
            }
        }

        idxsCount = expandCount;
        short *buffer = idxs;
        idxs = expandIdxs;
        expandIdxs = buffer;
    }

    return 0;
#endif
}
// @lc code=end

