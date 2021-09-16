/*
 * @lc app=leetcode.cn id=18 lang=c
 *
 * [18] 四数之和
 */

// @lc code=start

#define SUM(a,b,c,d)    (sortnums[a]+sortnums[b]+sortnums[c]+sortnums[d])
#define EXIST(a,b,c,d)  (answers[answer_num - 1][0] == sortnums[a] && \
                         answers[answer_num - 1][1] == sortnums[b] && \
                         answers[answer_num - 1][2] == sortnums[c])

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    int *sortnums;

    if (numsSize <4) {
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

    int i1, i2, j, k;
    int value;
    int answers[100000][4];
    int answer_num = 0;
    
    //排序
    sortnums[0] = nums [0];
    for (i1 = 1; i1 < numsSize; i1 ++) {
        value = nums[i1];
        for (j = i1 - 1; j >= 0; j --) {
            if (sortnums[j] > value) {
                sortnums[j + 1] = sortnums[j];
            } else {
                break;
            }
        }
        sortnums [j+1] = value;
    }

    //i is the mid of the 3 numbers
    for (i1 = 1; i2 < numsSize - 2; i1 ++) 
    {
        for (i2 = i1 + 1; i2 < numsSize -1; i2++) 
        {
            int equal = 0;
            j = i1 - 1;
            k = i2 + 1;

            if (sortnums[i1] == sortnums[i1-1]) {
                equal = 1;
            }

            //最小的可能都>0, 再往右移动没意义，不会有新的答案，退出
            if (SUM(0, i1, i2, k) > target) {
                goto out;
            }

            //最大的可能都<0, i不动，j，k怎么移动都没意义，直接移动i，往后寻找
            if (SUM(j, i1, i2, numsSize -1 ) < target) {
                continue;
            }

            do {
                value = SUM(j, i1, i2, k);;
                if ( value == target) {
                    int changej=0, changek = 0;

                    if ((answer_num == 0) || !EXIST(j, i1, i2, k)) {
                        //New answer
                        answers[answer_num][0] = sortnums[j]; 
                        answers[answer_num][1] = sortnums[i1];
                        answers[answer_num][2] = sortnums[i2];
                        answers[answer_num][3] = sortnums[k];
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
                } else if (value > target ) {
                    if (j > 0 ) {
                        j -- ;
                        if (equal) {
                            if (sortnums[j] != sortnums [i1]) {
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

            //move i2 to to a different value
            while ((i2 < numsSize -1) && (sortnums[i2 + 1] == sortnums [i2]))
            {
                i2++;
            }          
        }
    }

out:
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

    int *ret_ele = malloc (4*sizeof(int)*answer_num) ;
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
        rSizes[num] = 4;
        ret[num] = &ret_ele[4 * num];
        ret[num][0] = answers[num][0];
        ret[num][1] = answers[num][1];
        ret[num][2] = answers[num][2];
        ret[num][3] = answers[num][3];
    }

    return ret;
}
// @lc code=end

