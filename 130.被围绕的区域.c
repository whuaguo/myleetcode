/*
 * @lc app=leetcode.cn id=130 lang=c
 *
 * [130] 被围绕的区域
 */

// @lc code=start

void infect(char **board, int boardSize, int *boardColSize, int i, int j)
{
    if (i < 0 || i >= boardSize ||
        j < 0 || j >= boardColSize[0] ||
        board[i][j] != 'O')
    {
        return;
    }

    board[i][j] = 'o';
    infect(board, boardSize, boardColSize, i - 1, j);
    infect(board, boardSize, boardColSize, i + 1, j);
    infect(board, boardSize, boardColSize, i, j - 1);
    infect(board, boardSize, boardColSize, i, j + 1);
}

void solve(char **board, int boardSize, int *boardColSize)
{
    //如果为空，或只有一行，或只有一列，不用做任何操作
    if (!board || !boardSize ||
        boardSize == 1 || boardColSize[0] == 1)
    {
        return;
    }

    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardColSize[0]; j++)
        {
            if ((!i || (i == boardSize - 1) ||
                 !j || (j == boardColSize[0] - 1)) &&
                (board[i][j] == 'O'))
            {
                //边上并且为O
                infect(board, boardSize, boardColSize, i, j);
            }
        }
    }

    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardColSize[0]; j++)
        {
            if (board[i][j] == 'o')
            {
                board[i][j] = 'O';
            }
            else if (board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }
        }
    }
}
// @lc code=end
