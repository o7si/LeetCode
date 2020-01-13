class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        int i = 0, j = 0, k = 0;
        while (k < n * n) {
            
            // →
            while (j < n && matrix[i][j] == 0)
                matrix[i][j ++] = ++ k;
            -- j;
            ++ i;

            // ↓
            while (i < n && matrix[i][j] == 0)
                matrix[i ++][j] = ++ k;
            -- i;
            -- j;

            // ←
            while (j >= 0 && matrix[i][j] == 0)
                matrix[i][j --] = ++ k;
            ++ j;
            -- i;

            // ↑
            while (i >= 0 && matrix[i][j] == 0)
                matrix[i --][j] = ++ k;
            ++ i;
            ++ j;
        }

        return matrix;
    }
};
