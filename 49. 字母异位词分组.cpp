class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<int> primeTable = {
            2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 
            31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
            73, 79, 83, 97, 101, 103
        };

        map<double, vector<string>> m;
        for (int i = 0; i < strs.size(); ++ i) {

            double tmp = 1;
            for (int j = 0; j < strs[i].size(); ++ j)
                tmp *= primeTable[strs[i][j] - 'a'];
            m[tmp].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for (const auto& elem : m)
            result.push_back(elem.second);
        return result;
    }
};
