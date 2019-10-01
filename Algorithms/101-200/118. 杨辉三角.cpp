class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> result;
        for (int i = 1; i <= numRows; ++ i)
            result.push_back(vector<int>(i, 1));

        for (int i = 2; i < result.size(); ++ i)
            for (int j = 1; j < result[i].size() - 1; ++ j)
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];

        return result;
    }
};
