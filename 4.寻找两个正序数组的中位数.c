/*
 * @lc app=leetcode.cn id=4 lang=c
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int idx1 = 0,idx2 = 0;
    int mid_idx1, mid_idx2;
    int total_size = nums1Size+nums2Size;
    int mid_value;
    int midx;

    if (total_size == 0) {
        return 0;
    }

    //两个中位数的序列号
    if (total_size % 2 ) {
        //奇数个数，取中间值
        mid_idx1 = total_size / 2 ;
        mid_idx2 = mid_idx1;
    } else {
        //偶数个数，取中间两个值
        mid_idx1 = total_size / 2 - 1;
        mid_idx2 = mid_idx1 + 1;
    }

    while  ((idx1 < nums1Size)||( idx2 < nums2Size) ){
        if ((nums2Size == 0) || (idx2==nums2Size)) {
            //2到头或没有
            idx1 ++;
            midx = 1;
        } else if ((nums1Size == 0) || (idx1==nums1Size)) {
            //1到头或没有
            idx2 ++;
            midx = 2;
        } else if ((nums1[idx1] < nums2 [idx2])){
            idx1 ++;
            midx = 1;
        } else {
            idx2 ++;
            midx = 2;
        }
        
        //到达第一个下标
        if ( (idx1 + idx2) == (mid_idx1 + 1) ) {
            //找到第一个数
            mid_value = ((midx == 1)? nums1[idx1 - 1]:nums2[idx2 - 1]);
            
            if (mid_idx1 == mid_idx2) {
                //只有一个中位数，直接返回
                return mid_value;
            } 
        } else if ((idx1 + idx2) == (mid_idx2 + 1)) {
            //找到第二个了，直接加上
            mid_value += ((midx == 1)? nums1[idx1 - 1]:nums2[idx2 - 1]);

            //除以2返回
            return (double)mid_value / 2;
        }
    }

    return 0;
}
// @lc code=end

