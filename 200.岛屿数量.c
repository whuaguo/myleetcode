<<<<<<< HEAD
/*
 * @lc app=leetcode.cn id=200 lang=c
 *
 * [200] 岛屿数量
 */

// @lc code=start

//感染函数
static void expand(char** grid, int i, int j, int row, int col){
    grid[i][j] = '0';

    if ((i < row - 1) && (grid[i+1][j] == '1'))
        expand(grid, i + 1, j, row, col);
    
    if ((i > 0)&& (grid[i-1][j] == '1'))
        expand(grid, i - 1, j, row, col);
    
    if ((j < col -1)&& (grid[i][j+1] == '1'))
        expand(grid, i, j + 1, row, col);
    
    if ((j > 0)&& (grid[i][j-1] == '1'))
        expand(grid, i, j - 1, row, col);
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int islandNum = 0;
    int col = gridColSize[0];
    
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < col ; j++){
            if(grid[i][j] == '1'){
                expand(grid, i, j, gridSize, col);
                islandNum++;
            }
        }
    }
    return islandNum;
}
// @lc code=end

=======
/*
 * @lc app=leetcode.cn id=200 lang=c
 *
 * [200] 岛屿数量
 */

// @lc code=start

//感染函数
static void expand(char** grid, int i, int j, int row, int col){
    grid[i][j] = '0';

    if ((i < row - 1) && (grid[i+1][j] == '1'))
        expand(grid, i + 1, j, row, col);
    
    if ((i > 0)&& (grid[i-1][j] == '1'))
        expand(grid, i - 1, j, row, col);
    
    if ((j < col -1)&& (grid[i][j+1] == '1'))
        expand(grid, i, j + 1, row, col);
    
    if ((j > 0)&& (grid[i][j-1] == '1'))
        expand(grid, i, j - 1, row, col);
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int islandNum = 0;
    int col = gridColSize[0];
    
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < col ; j++){
            if(grid[i][j] == '1'){
                expand(grid, i, j, gridSize, col);
                islandNum++;
            }
        }
    }
    return islandNum;
}
// @lc code=end

>>>>>>> b9e17ed08f68eccf15d14565f758e023fbb7ed3d
