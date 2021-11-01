/*
 * @lc app=leetcode.cn id=204 lang=c
 *
 * [204] 计数质数
 */

// @lc code=start


static bool flag[5000000] = {false};

int countPrimes(int n){
    if (n <= 2) {
        return 0;
    }

    if (!flag[0]) {
        for(int i = 3; i < 5000000; i += 2) {
            if(!flag[i])
            {
                for(int j = i << 1; j < 5000000; j += i)
                    flag[j] = true;
            }
        }
        flag[0] = true;
    }

    int count = 1;
    for (int i = 3; i < n; i += 2) {
        if (!flag[i]) count++;
    }
   
    return count;
}
// @lc code=end

