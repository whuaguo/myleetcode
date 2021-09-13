/*
 * @lc app=leetcode.cn id=11 lang=c
 *
 * [11] 盛最多水的容器
 */

// @lc code=start

inline int min_num(i, j) {
    return (i < j)? i: j;
}

int maxArea(int* height, int heightSize){
    int idx1, idx2;
    int len;
    int max;

    if (heightSize < 2 ) {
        return 0;
    }

    idx1 = 0;
    idx2 = heightSize - 1;
    len = heightSize - 1;
    max = len * min_num(height[idx1], height[idx2]);

    //解题思路，(i,j)每次移动长度较小的那条边，变成（i+1,j)或（i, j -1)
    //只要移动的是高度较小的那个边，那么就不可能丢失最大面积的肯能。
    //证明：  
    //假定i对应的高度较低，那么变成（i+1，j)之后，丢失掉的可能组合是（i, j-1),
    //(i, j-2), (i, j-3).... (i, i+1), 所有的这些高度只会比i更低或一样，宽度
    //更小，所以面积只能更小。
    while (idx1 < idx2) {
        int new_size;

        if (height[idx1] < height[idx2]) {
            idx1++;
        } else {
            idx2--;
        }
        
        len--;
        new_size = len * min_num(height[idx1], height[idx2]);
        if (new_size > max) {
            max = new_size;
        } 
    }

    return max;
}
// @lc code=end

