class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        if (nums.empty())
            return "0";

        vector<string> snums;
        for (int i = 0; i < nums.size(); ++ i)
            snums.push_back(to_string(nums[i]));
        
        string result;
        sort(snums.begin(), snums.end(), [](const string& lhs, const string& rhs) {
            return lhs + rhs > rhs + lhs;
        });
        for (int i = 0; i < snums.size(); ++ i)
            result += snums[i];
        return result[0] == '0' ? "0" : result;
    }
};
