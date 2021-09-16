/*
 * @lc app=leetcode.cn id=16 lang=c
 *
 * [16] 最接近的三数之和
 */

// @lc code=start

inline short gap(short a, short b) {
    return (a>b)?(a-b):(b-a);
}

inline short new_gap(short a, short b) {
    return ((a)>(b))?(b):(a);
}

#define SUM(i,j,k) (sortnums[i] + sortnums[j] + sortnums[k])


int threeSumClosest(int* nums, int numsSize, int target){
    short ret_value = 0;
    short min_gap = 0x7FFF;

    //总数小于等于3，直接返回总和
    if (numsSize <= 3) {
        for (int i = 0 ; i < numsSize; i ++ ) {
            ret_value += nums[i];
        }
        return ret_value;
    }

    short *sortnums;
    sortnums = malloc (sizeof(short)*numsSize);
    if (sortnums == NULL) {
        return 0;
    }

    short i, j, k;
    short value;
    
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

    for (i = 1; i < numsSize - 1; i++) {
        short sum_value;
        short current_gap; 
        j = i - 1;
        k = i + 1;

        //当前最小可能
        sum_value = SUM(0,i,k);
        if (sum_value > target) {
            current_gap = gap(sum_value, target);
            if (current_gap < min_gap) {
                ret_value = sum_value;
            }

            free(sortnums);
            return ret_value;
        }

        //当前最大可能
        sum_value = SUM(j, i , numsSize - 1);
        if (sum_value < target) {
            current_gap = gap(sum_value, target);
            if (current_gap < min_gap) {
                min_gap = current_gap;
                ret_value = sum_value;
            }
            continue;
        }

        do {
            sum_value = SUM(j,i,k);
            if (sum_value == target) {
                //相等就直接返回
                free(sortnums);
                return sum_value;
            } 

            current_gap = gap(sum_value, target);
            if (current_gap < min_gap) {
                min_gap = current_gap;
                ret_value = sum_value;
            }

            if (sum_value > target ) {
                if (j > 0 ) {
                    j -- ;
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

    free(sortnums);
    return ret_value;
}
// @lc code=end

