/*
 * @lc app=leetcode.cn id=15 lang=c
 *
 * [15] 三数之和
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int *sortnums;

    if (numsSize <3) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    sortnums = malloc (sizeof(int)*numsSize);
    if (sortnums == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int i, j, k;
    int value;
    int answers[100000][3];
    int answer_num = 0;
    
    //排序
    sortnums[0] = nums [0];
    for (i = 1; i < numsSize; i ++) {
        value = nums[i];
        for (j = i - 1; j >= 0; j --) {
            if (sortnums[j] > value) {
                sortnums[j + 1] = sortnums[j];
            } else {
                break;
            }
        }
        sortnums [j+1] = value;
    }

    //i is the mid of the 3 numbers
    for (i = 1; i < numsSize - 1; i ++) {
        int equal = 0;
        j = i - 1;
        k = i + 1;

        if (sortnums[i] == sortnums[i-1]) {
            equal = 1;
        }

        //最小的可能都>0, 再往右移动没意义，不会有新的答案，退出
        if (sortnums[0] + sortnums[i] + sortnums[k] >0) {
            break;
        }

        //最大的可能都<0, i不动，j，k怎么移动都没意义，直接移动i，往后寻找
        if (sortnums[j] + sortnums[i] + sortnums[numsSize -1] < 0) {
            continue;
        }

        do {
            value = sortnums[i] + sortnums[j] + sortnums[k];
            if ( value == 0) {
                int changej=0, changek = 0;

                if ((answer_num == 0) ||
                    (answers[answer_num-1][0] != sortnums[j]) || 
                    (answers[answer_num-1][1] != sortnums[i])) {
                    //New answer
                    answers[answer_num][0] = sortnums[j]; 
                    answers[answer_num][1] = sortnums[i];
                    answers[answer_num][2] = sortnums[k];
                    answer_num ++;
                }

                //check if can move one step, if no, break;
                if ((j == 0) || (k == numsSize -1)) {
                    break;
                }

                //move 2 meaningful step
                if (j > 0) {
                    do {
                        j--;
                    } while ((sortnums[j] == sortnums[j+1]) && (j >0));
                    
                    if (sortnums[j] != sortnums [j+1]) {
                        if (equal) {
                            break;
                        }
                    } else {
                        break;
                    }
                } 
                
                if (k < numsSize -1) {
                   do {
                       k ++;
                   } while ((k < numsSize -1) && (sortnums[k] == sortnums[k - 1]));
                
                    if (sortnums[k] == sortnums[k -1 ]) {
                        break;
                    }
                } 
            } else if (value > 0 ) {
                if (j > 0 ) {
                    j -- ;
                    if (equal) {
                        if (sortnums[j] != sortnums [i]) {
                            break;
                        }
                    }
                 } else {
                    break; //not possible to find a small value to get 0
                }
            } else {
                if (k < (numsSize - 1)) {
                    k ++;
                } else {
                    break;
                }
            }
        } while ((j>=0) && (k <= (numsSize-1)));
    }

    if (answer_num == 0) {
        free(sortnums);
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int **ret = (int **)malloc( sizeof(int *)*answer_num);
    if (ret == NULL) {
        free(sortnums);
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int *rSizes = malloc(sizeof(int)*answer_num );
    if (*rSizes == NULL) {
        free(sortnums);
        free(ret);
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int *ret_ele = malloc (3*sizeof(int)*answer_num) ;
    if (ret_ele == NULL) {
        free(sortnums);
        free(rSizes);
        free(ret);
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }


    *returnSize = answer_num;
    *returnColumnSizes = rSizes;
    for (int num = 0; num < answer_num; num ++) {
        rSizes[num] = 3;
        ret[num] = &ret_ele[3 * num];
        ret[num][0] = answers[num][0];
        ret[num][1] = answers[num][1];
        ret[num][2] = answers[num][2];
    }

    return ret;
}
// @lc code=end

