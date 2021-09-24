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

struct sodu_flag_count {
    unsigned short exist_flag:12;
    unsigned short exist_count:4;
};

static struct sodu_flag_count sudo_status[3][9] = {0};

//判断key是否能放入数独表内，通过判断横纵、九宫格内的数字bit-map快速判断
#define isKeyExist(i, j, key) (\
    (1 << (key - '1')) & \
    (sudo_status[0][i].exist_flag | \
     sudo_status[1][j].exist_flag | \
     sudo_status[2][nums2idx(i,j)].exist_flag))

//把key放入数独表内，需要添加数字bit-map并修改数字数目
static void addSoduFlag(short i, short j, char key) {
    unsigned short flag_bit = (1 << (key - '1'));
    sudo_status[0][i].exist_flag |= flag_bit; 
    sudo_status[1][j].exist_flag |= flag_bit; 
    sudo_status[2][nums2idx(i,j)].exist_flag |= flag_bit; 
}

static void addSoduCount(short i, short j) {
    sudo_status[0][i].exist_count ++;
    sudo_status[1][j].exist_count ++;
    sudo_status[2][nums2idx(i,j)].exist_count ++;
}

//把key从数独表中移除，需要清除数字bit-map并修改数字数目
static void removeSoduFlag(short i, short j, char key) {
    unsigned short flag_bit = (1 << (key - '1'));
    sudo_status[0][i].exist_flag ^= flag_bit; 
    sudo_status[1][j].exist_flag ^= flag_bit; 
    sudo_status[2][nums2idx(i,j)].exist_flag ^= flag_bit; 
} 

//把key从数独表中移除，需要清除数字bit-map并修改数字数目
static void removeSoduCount(short i, short j) {
    sudo_status[0][i].exist_count --;
    sudo_status[1][j].exist_count --;
    sudo_status[2][nums2idx(i,j)].exist_count --;
} 

//初始化bit-map和数字数目表，顺便检查九宫格是否合法
static bool initExistFlag(char **board, int boardSize, int* boardColSize) {
    memset(sudo_status, 0, sizeof(struct sodu_flag_count) * 3 * 9);

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
                addSoduCount(i, j);
            }
        }
    }

    return true;
}

//在横纵、九宫格中找一个已经填入数字最多的维度
static unsigned char findMax(char** board, unsigned char *idx1, unsigned char *idx2) {
    unsigned char max = 0;
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 9; j++) {
            //如果数字数目已经为9，代表已经填满，需要跳过
            if ( (sudo_status[i][j].exist_count!=9) && (sudo_status[i][j].exist_count > max)) {
                max = sudo_status[i][j].exist_count;
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
static bool findSudoku(char** board) {
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
                addSoduCount(i,j);
                for (char key = '1'; key <= '9'; key ++) {
                    //依次尝试每种可能
                    if (isKeyExist(i, j, key)) {
                        continue;
                    }
                    
                    board[i][j] = key;
                    addSoduFlag(i,j,key);
                    if (findSudoku(board)) {
                        return true;
                    } else {
                        removeSoduFlag(i,j,key);
                    } 
                } 
                board[i][j] = '.';
                removeSoduCount(i,j);
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

