/*
 * @lc app=leetcode.cn id=31 lang=c
 *
 * [31] 下一个排列
 */

// @lc code=start


void nextPermutation(int* nums, int numsSize){
    int idx;

    //没有或只有一个数，直接返回
    if (numsSize <=1) {
        return;
    }

    idx = numsSize - 1;
    //至少有两个, 低位往高位找到第一个比高位大的数字
    while ((idx > 0) && (nums[idx] <= nums[idx - 1])) {
        idx --;
    }

    int buffer;
    int i = idx;
    int j;

    //再从低位中找到第一个比高位大的数
    if (idx != 0) {
        j = numsSize - 1;
        while (j >= idx ) {
            if (nums[j] > nums[idx -1]) {
                break;
            }
            j --;
        }

        //把这个数和高位数字调换一下，那么现在高位已经换成了后面最小的
        buffer = nums[j];
        nums[j] = nums[idx - 1];
        nums[idx - 1] = buffer;
    } 

    //idx - 1 后面的数字现在是倒叙，需要颠倒一下
    j = numsSize - 1;
    while (i < j) {
        buffer = nums[i];
        nums[i] = nums[j];
        nums[j] = buffer;
        i++;
        j--;
    }

    return;
}
// @lc code=end

