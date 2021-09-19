/*
 * @lc app=leetcode.cn id=36 lang=c
 *
 * [36] 有效的数独
 */

// @lc code=start
#define num2i(i) ((i < 3) ? 0 : ((i < 6)? 3 : 6))
#define num2j(i) ((i < 3) ? 0 : ((i < 6)? 1 : 2))

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    short flag[3][9] = {0};

    if (boardSize != 9) {
        return false;
    }

    for (short i = 0; i < 9; i ++) {
        short idx_base = num2i(i);
        if (boardColSize[i] != 9) {
            return false;
        }

        for (short j = 0; j < 9; j++) {
            char value = board[i][j]; 
            if ( value == '.') {
                continue;
            } 
            
            if ((value <'1') || (value >'9')) {
                return false;
            }
            
            short idx = idx_base + num2j(j);
            short flag_bit = (1 << (value - '1'));

            if ((flag[0][i] & flag_bit) ||
                (flag[1][j] & flag_bit) ||
                (flag[2][idx] & flag_bit)) {
                return false;
            } else {
                flag[0][i] |= flag_bit;
                flag[1][j] |= flag_bit;
                flag[2][idx] |= flag_bit;
            }
        }
    }

    return true;
}
// @lc code=end

