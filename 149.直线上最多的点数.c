/*
 * @lc app=leetcode.cn id=149 lang=c
 *
 * [149] 直线上最多的点数
 */

// @lc code=start


int maxPoints(int** points, int pointsSize, int* pointsColSize){
    int maxPointCount = 1;
    for (int i = 0; i < pointsSize - 1; i++) {
        int x1 = points[i][0];
        int y1 = points[i][1];
        for (int j = i + 1; j < pointsSize; j++) {
            int dy = (points[j][1] - y1);
            int dx = (points[j][0] - x1);
            int pointCount = 2;

            for (int k = j + 1; k < pointsSize; k++) {
                int x = points[k][0], y = points[k][1];
                if (dx*(y1 - y) == dy*(x1 - x)) {
                    pointCount++;    //行列式值为0，两向量共线
                }
            }

            if (maxPointCount < pointCount) {
                maxPointCount = pointCount;
            }
        }
    }

    return maxPointCount;
}
// @lc code=end

