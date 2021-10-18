/*
 * @lc app=leetcode.cn id=134 lang=c
 *
 * [134] 加油站
 */

// @lc code=start

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int gasAll = 0;
    int gasInCar = 0;
    int start = 0;

    for (int idx = 0; idx < gasSize; idx++){
        gasInCar += gas[idx] - cost[idx];

        if (gasInCar < 0){
            start = idx + 1;
            gasAll += gasInCar;
            gasInCar = 0;
        }
    }

    gasAll += gasInCar;
    return gasAll < 0 ? -1: start;
}
// @lc code=end

