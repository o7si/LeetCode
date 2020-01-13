class Solution {
public:
    vector<int> grayCode(int n) {
        
        if (n == 0)
            return vector<int>(1, 0);

        vector<int> result;
        for (int i = 0; i < (2 << n - 1); ++ i)
            result.push_back(i ^ (i >> 1));
        return result;
    }
};
