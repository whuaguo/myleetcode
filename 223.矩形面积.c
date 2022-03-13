/*
 * @lc app=leetcode.cn id=223 lang=c
 *
 * [223] 矩形面积
 */

// @lc code=start


int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
    int asum = (ax2 - ax1) * (ay2 - ay1);
    asum += (bx2 - bx1) * (by2 - by1);

    if ((bx1 >= ax2) || (ax1 >= bx2) ||  
        (by1 >= ay2) || (ay1 >= by2)) {
        return asum;
    }

    int l = (bx2 > ax2) ? ax2 : bx2;
    int h = (by2 > ay2) ? ay2 : by2;
    l -= (bx1 > ax1) ? bx1 : ax1;
    h -= (by1 > ay1) ? by1 : ay1;

    return asum - l * h;
}
// @lc code=end

