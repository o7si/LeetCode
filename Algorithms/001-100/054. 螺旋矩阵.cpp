class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        if (matrix.empty())
            return vector<int>();

        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        vector<int> result;
        int i = 0, j = -1;
        while (result.size() < m * n) {
            
            // 右
            while (j + 1 < n && !vis[i][j + 1]) {
                
                result.push_back(matrix[i][j + 1]);
                vis[i][j + 1] = true;
                ++ j; 
            }
            // 下
            while (i + 1 < m && !vis[i + 1][j]) {
                
                result.push_back(matrix[i + 1][j]);
                vis[i + 1][j] = true;
                ++ i;
            }
            // 左
            while (j - 1 >= 0 && !vis[i][j - 1]) {

                result.push_back(matrix[i][j - 1]);
                vis[i][j - 1] = true;
                -- j;
            }
            // 上
            while (i - 1 >= 0 && !vis[i - 1][j]) {

                result.push_back(matrix[i - 1][j]);
                vis[i - 1][j] = true;
                -- i;
            }
        }
        return result;
    }
};
