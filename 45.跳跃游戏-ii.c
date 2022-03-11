/*
 * @lc app=leetcode.cn id=45 lang=c
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start


int jump(int* nums, int numsSize){
    //只有一个元素，直达
    if (numsSize == 1) {
        return 0;
    }

    //一步可达
    int max = nums[0];
    if (max >= numsSize - 1) {
        return 1;
    }

    int idx = 1;
    int steps = 1;

    //如果可能到达的地方比起点远，从起点继续探索
    while (max >= idx) {
        steps++;

        //尝试起点到max的下一步，看看能不能再往前走
        int oldMax = max;
        for (int i = idx; i <= oldMax; i++) {
            if (max < i + nums[i]) {
                //还可以往前走，更新最远的标签
                max = i + nums[i];

                //如果已经到达目的，直接返回
                if (max >= (numsSize - 1)) {
                    return steps;
                }
            }
        }

        //更新起点和步数
        idx = oldMax + 1;
    }

    //没法前进而且没有到达目的，返回false
    return steps;
}
// @lc code=end

