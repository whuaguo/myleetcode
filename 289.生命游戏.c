/*
 * @lc app=leetcode.cn id=289 lang=c
 *
 * [289] 生命游戏
 */

// @lc code=start

void gameOfLife(int **board, int boardSize, int *boardColSize)
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardColSize[i]; j++)
        {
            int lives;

            //计算lives的数目的时候，使用最低位
            lives = i && (j > 0) && (board[i - 1][j - 1] & 1) ? 1 : 0;
            lives += i && (board[i - 1][j] & 1) ? 1 : 0;
            lives += i && (j + 1 < boardColSize[i]) && (board[i - 1][j + 1] & 1) ? 1 : 0;

            lives += (i >= 0) && j && (board[i][j - 1] & 1) ? 1 : 0;
            lives += (i >= 0) && (j + 1 < boardColSize[i]) && (board[i][j + 1] & 1) ? 1 : 0;

            lives += (i + 1 < boardSize) && j && (board[i + 1][j - 1] & 1) ? 1 : 0;
            lives += (i + 1 < boardSize) && (board[i + 1][j] & 1) ? 1 : 0;
            lives += (i + 1 < boardSize) && (j + 1 < boardColSize[i]) && (board[i + 1][j + 1] & 1) ? 1 : 0;

            //把下一轮的结果放入倒数第二位
            if (board[i][j])
            {
                if (lives == 2 || lives == 3)
                    board[i][j] |= 2;
            }
            else
            {
                if (lives == 3)
                    board[i][j] |= 2;
            }
        }
    }

    //计算完毕，右移一位把最新结果放入最低位，上一轮结果消除
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardColSize[i]; j++)
        {
            board[i][j] >>= 1;
        }
    }
}
// @lc code=end

