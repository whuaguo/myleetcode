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

#define INVALID_IDX     -1
#define BEGIN_IDX       wordListSize
#define END_IDX         wordListSize + 1
#define TARGET_IDX      wordListSize + 2
#define idx2word(idx)   ((idx == BEGIN_IDX) ? beginWord : wordList[idx])

int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
    short nextToEnd[5000] = {0};   //path to end
    short nextToStart[5000] = {0}; //path to begin

    short idxs1[1000] = {0};        //用来存储从begin，end开始的集合，还有下一个迭代的集合
    short idxs2[1000] = {0};
    short idxs3[1000] = {0};
    short *eidxs = idxs1;           //从begin开始
    short *sidxs = idxs2;           //从end开始
    short *expandIdxs = idxs3;      //下一次迭代

    short eidxsCount = 0;           //刚开始只有endword
    short edepth = 2;               //eidxs里面的是endword的邻居

    memset(nextToEnd, INVALID_IDX, 5000*sizeof(short));
    //判断endword是否在wordList中,顺便把endWord的邻居放入eidxs集合里面
    for (int idx = 0; idx < wordListSize; idx++) {
        int diffs = strDiffs(wordList[idx], endWord); 
        if ( diffs == 0) {
            nextToEnd[idx] = TARGET_IDX;
            nextToEnd[TARGET_IDX] = idx;
        } else if (diffs == 1) {
            eidxs[eidxsCount++] = idx;
            nextToEnd[idx] = END_IDX;
        }
    }

    if (nextToEnd[TARGET_IDX] == INVALID_IDX) {
        //endword不在wordList里面，直接返回0
        return 0;
    }

    bool isNeighbor = (strDiffs(beginWord, endWord) == 1);
    if (isNeighbor) {
        return 2;
    }

    short sidxsCount = 1;           //刚开始只有beginword
    short sdepth = 1;               //只有beginword自己
    sidxs[0] = BEGIN_IDX;
    memset(nextToStart, INVALID_IDX, 5000*sizeof(short));

    while (eidxsCount && sidxsCount) {
        bool    is2end = (eidxsCount && (eidxsCount < sidxsCount)); 
        short*  idxsCount = is2end ? &eidxsCount: &sidxsCount;
        short*  depth = is2end ? &edepth: &sdepth;
        short*  paths = is2end ? nextToEnd : nextToStart;
        short*  rpaths = is2end ? nextToStart: nextToEnd;
        short** idxs = is2end ? &eidxs : &sidxs;

        int expandCount = 0;
        for (int idx = 0; idx < *idxsCount; idx++) {
            char *targetWord = idx2word((*idxs)[idx]);

            for (int i = 0; i < wordListSize; i++) {
                if (INVALID_IDX != paths[i]) {
                    continue;
                } 

                int diffs = strDiffs(targetWord, wordList[i]); 
                if (1 == diffs) {
                    if (INVALID_IDX != rpaths[i]) {
                        return edepth + sdepth;
                    }
                    paths[i] = (*idxs)[idx];
                    expandIdxs[expandCount++] = i;
                }
            }
        }

        short *buffer = expandIdxs;
        expandIdxs = *idxs;
        *idxs = buffer;
        *idxsCount = expandCount;

        if (expandCount) {
            (*depth)++;
        }
    }

    return 0;
}
// @lc code=end

