/*
 * @lc app=leetcode.cn id=126 lang=c
 *
 * [126] 单词接龙 II
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//判断两个字符串是否只有一个字符不同
bool isNeighbor(char * s1, char * s2) {
    int len = strlen(s1);

    if (len != strlen(s2)) {
        return false;
    }

    int diffs = 0;
    for (int i = 0; i < len; i++) {
        if (s1[i] != s2[i]) {
            diffs++;
            if (diffs > 1) {
                return false;
            }
        } 
    }

    return (diffs == 1);
}

//是否能够由beginWord变化而成

char *** findLadders(char * beginWord, char * endWord, char ** wordList, int wordListSize, int* returnSize, int** returnColumnSizes){
    bool bNeighbor[5000] = {false};
    bool eNeighbor[5000] = {false};

    for (int i = 0; i < wordListSize; i++) {
        bNeighbor[i] = isNeighbor(beginWord, wordList[i]);
    }

    for (int i = 0; i < wordListSize; i++) {
        eNeighbor[i] = isNeighbor(endWord, wordList[i]);
    }

}
// @lc code=end

