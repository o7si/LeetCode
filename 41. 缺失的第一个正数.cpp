class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int i = 0;
        while (i < nums.size()) {

            if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
                
                swap(nums[i], nums[nums[i] - 1]);
                continue;
            }
            
            ++ i;
        }

        int res = 0;
        while (res < nums.size() && nums[res] == res + 1)
            ++ res;
        return res + 1;
    }
};
