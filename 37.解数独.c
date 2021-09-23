/*
 * @lc app=leetcode.cn id=37 lang=c
 *
 * [37] 解数独
 */

// @lc code=start

#define num2i(i) ((i < 3) ? 0 : ((i < 6)? 3 : 6))
#define num2j(i) ((i < 3) ? 0 : ((i < 6)? 1 : 2))
//通过横纵坐标得到九宫格序列号
#define nums2idx(i,j) (num2i(i) +num2j(j))

//横纵、九宫格里已经具备的数字bit-map，0-横，1-纵，2-九宫格
unsigned short exist_flag[3][9] = {0};
//横纵、九宫格里已经具备的数字数目，0-横，1-纵，2-九宫格
unsigned char exist_count[3][9] = {0};

//判断key是否能放入数独表内，通过判断横纵、九宫格内的数字bit-map快速判断
#define isKeyExist(i, j, key) \
    ((exist_flag[0][i] | exist_flag[1][j] | exist_flag[2][nums2idx(i,j)]) & \
    (1 << (key - '1')))


//把key放入数独表内，需要添加数字bit-map并修改数字数目
void addSoduFlag(short i, short j, char key) {
    unsigned short flag_bit = (1 << (key - '1'));
    exist_flag[0][i] |= flag_bit; 
    exist_flag[1][j] |= flag_bit; 
    exist_flag[2][nums2idx(i,j)] |= flag_bit; 
    exist_count[0][i] ++;
    exist_count[1][j] ++;
    exist_count[2][nums2idx(i,j)] ++;
}

//把key从数独表中移除，需要清除数字bit-map并修改数字数目
void removeSoduFlag(short i, short j, char key) {
    unsigned short flag_bit = (1 << (key - '1'));
    exist_flag[0][i] ^= flag_bit; 
    exist_flag[1][j] ^= flag_bit; 
    exist_flag[2][nums2idx(i,j)] ^= flag_bit; 
    exist_count[0][i] --;
    exist_count[1][j] --;
    exist_count[2][nums2idx(i,j)] --;
} 

//初始化bit-map和数字数目表，顺便检查九宫格是否合法
bool initExistFlag(char **board, int boardSize, int* boardColSize) {
    memset(exist_flag, 0, sizeof(unsigned short) * 3 * 9);
    memset(exist_count, 0, sizeof(unsigned char) * 3 * 9);

    if (boardSize != 9) {
        return false;
    }

    for (short i = 0; i < 9; i ++) {
        if (boardColSize[i] != 9) {
            return false;
        }

        for (short j = 0; j < 9; j++) {
            char key = board[i][j]; 
            if ( key == '.') {
                continue;
            } 
            
            if ((key <'1') || (key >'9') || isKeyExist(i, j, key)) {
                return false;
            } else {
                addSoduFlag(i, j, key);
            }
        }
    }

    return true;
}

//在横纵、九宫格中找一个已经填入数字最多的维度
unsigned char findMax(char** board, unsigned char *idx1, unsigned char *idx2) {
    unsigned char max = 0;
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 9; j++) {
            //如果数字数目已经为9，代表已经填满，需要跳过
            if ( (exist_count[i][j]!=9) && (exist_count[i][j] > max)) {
                max = exist_count[i][j];
                *idx1 = i;
                *idx2 = j;

                //已经为8了，是最大的可能，直接返回
                if (max == 8) {
                    return max;
                }
            }
        }
    }

    return max;
}

//循环递归查找答案
bool findSudoku(char** board) {
    unsigned char idx1;
    unsigned char idx2;

    //先找个缺数字最少的维度
    if (findMax(board, &idx1, &idx2) == 0) {
        return true;
    }

    unsigned char i_base; //横坐标起始
    unsigned char j_base; //纵坐标起始
    unsigned char i_loop; //横坐标循环个数
    unsigned char j_loop; //纵坐标循环个数

    if (idx1 ==0) {
        //横坐标确定，纵坐标从1到9
        i_base = idx2;
        j_base = 0;
        i_loop = 1;
        j_loop = 9;
    } else if (idx1 == 1) {
        //纵坐标确定，横坐标从1到9
        i_base = 0;
        j_base = idx2;
        i_loop = 9;
        j_loop = 1;
    } else {
        //九宫格确定，横坐标、纵坐标都是从1到3
        i_base = (idx2 / 3) * 3;
        j_base = (idx2 % 3) * 3;
        i_loop = 3;
        j_loop = 3;
    }

    for (int i = i_base; i < i_base + i_loop; i++) {
        for (int j = j_base; j < j_base + j_loop; j++) {
            if (board[i][j] == '.') {
                //第一个非.的位置
                for (char key = '1'; key <= '9'; key ++) {
                    //依次尝试每种可能
                    if (isKeyExist(i, j, key)) {
                        continue;
                    }
                    
                    addSoduFlag(i,j,key);
                    board[i][j] = key;
                    if (findSudoku(board)) {
                        return true;
                    } else {
                        removeSoduFlag(i,j,key);
                        board[i][j] = '.';
                    } 
                } 
                return false;
            }
        }
    }

    return false;
}

void solveSudoku(char** board, int boardSize, int* boardColSize){
    //初始化existflag, 顺便检查输入参数是否合法，如果不合法，就直接退出
    if (!initExistFlag(board, boardSize, boardColSize)) {
        return;
    }

    findSudoku(board);
}
// @lc code=end

