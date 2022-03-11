/*
 * @lc app=leetcode.cn id=55 lang=c
 *
 * [55] 跳跃游戏
 */

// @lc code=start


bool canJump(int* nums, int numsSize){
    int max = nums[0];
    int idx = 1;

    //一步可达，返回true
    if (max >= numsSize - 1) {
        return true;
    }

    //如果可能到达的地方比起点远，从起点继续探索
    while (max >= idx){
        int oldMax = max;

        //尝试起点到max的每一步，看看能不能再往前走
        for (int i = idx; i <= oldMax; i++) {
            if (max < i + nums[i]) {
                //还可以往前走，更新最远的标签
                max = i + nums[i];

                //如果已经到达目的，直接返回
                if (max >= (numsSize - 1)) {
                    return true;
                }
            }
        }

        //更新起点
        idx = oldMax + 1;
    }

    //没法前进而且没有到达目的，返回false
    return false;
}
// @lc code=end

