/*
 * @lc app=leetcode.cn id=80 lang=c
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start


int removeDuplicates(int* nums, int numsSize){
    int right = 1;
    int left = 0;  
    bool dupped = false;
    bool ever_removed = false;


    while (right < numsSize) {
        if (nums[right] == nums[left]) {
            if (dupped) {
                //已经有dup，只需要移动右边指针即可，总数--
                right++;
                ever_removed = true;
                continue;
            }
            //dup标记设置
            dupped = true;
        } else {
            //dup标记复位
            dupped = false;
        } 

        //移动左右指针，如果需要移动数组内的值
        left++;
        if (ever_removed) {
            nums[left] =nums[right];
        }
        right++;
    }

    return left + 1;
}
// @lc code=end

