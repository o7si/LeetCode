class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long>> dp(m, vector<long>(n, 0));
        dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;

        for (int i = 0; i < m; ++ i) {

            for (int j = 0; j < n; ++ j) {

                if (i == 0 && j == 0)
                    continue;

                if (obstacleGrid[i][j] == 1) {

                    dp[i][j] = 0;
                    continue;
                }

                if (i == 0) {

                    dp[i][j] = dp[i][j - 1];
                    continue;
                }

                if (j == 0) {

                    dp[i][j] = dp[i - 1][j];
                    continue;
                }

                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }

        return dp[m - 1][n - 1];
    }
};
