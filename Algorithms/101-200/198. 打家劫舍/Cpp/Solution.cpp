class Solution {
public:
    int rob(vector<int>& nums) {
        
        int maxAmount = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            
            int steal = nums[i] + (i - 2 < 0 ? 0 : nums[i - 2]);
            int nosteal = i - 1 < 0 ? 0 : nums[i - 1];
            maxAmount = nums[i] = max(steal, nosteal);
        }
        return maxAmount;
    }
};
