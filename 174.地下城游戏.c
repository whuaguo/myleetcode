/*
 * @lc app=leetcode.cn id=174 lang=c
 *
 * [174] 地下城游戏
 */

// @lc code=start


int calculateMinimumHP(int** dungeon, int dungeonSize, int* dungeonColSize){
    int colsize = dungeonColSize[0];
    int mins[1000][1000] = {0}; //从目的开始往回退，前一步最小值
    int min = 0;

    min = dungeon[dungeonSize - 1][colsize - 1];
    mins[dungeonSize - 1][colsize - 1] = (min > 0) ? 0 : min; 

    for (int idx = colsize - 2 ; idx >= 0; idx --) {
        min = dungeon[dungeonSize - 1][idx] + mins[dungeonSize - 1][idx + 1];
        mins[dungeonSize - 1][idx] = (min > 0) ? 0 : min;
    }

    for (int idx = dungeonSize - 2; idx >= 0; idx--) {
        min =  dungeon[idx][colsize - 1] + mins[idx + 1][colsize - 1];
        mins[idx][colsize - 1] = (min > 0) ? 0 : min;
    }

    for (int i = dungeonSize - 2; i >= 0; i--) {
        for (int j = colsize - 2; j >= 0; j--) {
            min = (mins[i][j+1] > mins[i+1][j]) ? mins[i][j+1]:mins[i+1][j];
            min = dungeon[i][j] + min;
            mins[i][j] = (min > 0) ? 0 : min;
        }
    }

    return (0 - mins[0][0]) + 1; 
}
// @lc code=end

