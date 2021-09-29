/*
 * @lc app=leetcode.cn id=52 lang=c
 *
 * [52] N皇后 II
 */

// @lc code=start
int qsn = 0;

static bool valid4Q(char *qs, char line, char key) {

    for (char i = 0; i < line; i++) {
        if ((qs[i] == key) ||                 /*同列*/
            ((line - i) == (key - qs[i])) ||  /*正斜线*/
            ((line - i) == (qs[i] - key))) {  /*反斜线*/
            return false;
        }
    }
 
    //valid for Queen
    return true;
}

void findQSolution(char *qs, char n, char line) {
    if (n <= line) {
        //find one solution
        qsn ++;
        return;
    }

    for (char i = 0; i < n; i ++) {
        if (valid4Q(qs, line, i)) {
            qs[line] = i;
            findQSolution(qs, n, line + 1);
        }
    }

    return;
}

int totalNQueens(int n){
    char qs[10] = {0};

    qsn = 0;

    findQSolution(qs, n, 0);

    return qsn;
}
// @lc code=end

