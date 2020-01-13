class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        matrix[0][0] = 1;

        for (int i = 0; i < m; ++ i) {

            for (int j = 0; j < n; ++ j) {

                if (i == 0 && j == 0)
                    continue;

                if (i == 0) {

                    matrix[i][j] = matrix[i][j - 1];
                    continue;
                }
                
                if (j == 0) {

                    matrix[i][j] = matrix[i - 1][j];
                    continue;
                }

                matrix[i][j] = matrix[i][j - 1] + matrix[i - 1][j];
            }
        }

        return matrix[m - 1][n - 1];
    }
};
