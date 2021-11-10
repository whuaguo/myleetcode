/*
 * @lc app=leetcode.cn id=215 lang=c
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start

//大顶堆调整函数
void maxNode(int *nums, int numsSize, int idx) {
    int left = (idx << 1) + 1;
    int right = left + 1;
    int maxIdx = idx;

    if ((left < numsSize) && (nums[maxIdx] < nums[left])) {
        maxIdx = left;
    }

    if ((right < numsSize) && (nums[maxIdx] < nums[right])) {
        maxIdx = right;
    }

    if (maxIdx != idx) {
        int temp = nums[idx];
        nums[idx] = nums[maxIdx];
        nums[maxIdx] = temp;

        //调整之后，如果子树还有孩子节点，就继续调整
        if (maxIdx < (numsSize >> 1)) {
            maxNode(nums, numsSize, maxIdx);
        }
    }
}

int findKthLargest(int* nums, int numsSize, int k){
    int idx = (numsSize - 2) >> 1;

    //构造大顶堆
    while (idx >= 0) {
        maxNode(nums, numsSize, idx);
        idx--;
    } 

    //一次把堆顶移开，把尾部调入堆顶，然后调整堆，重复k-1次
    for (int i = 0; i < k - 1; i++) {
        nums[0] = nums[numsSize - 1 - i];
        maxNode(nums, numsSize - i - 1, 0);        
    }

    //堆顶就是第K大的数
    return nums[0];
}
// @lc code=end

