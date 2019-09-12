class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;

        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size()) {

            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                
                int res = nums[i] + nums[left] + nums[right];
                if (res < 0) {
                    
                    ++ left;
                } else if (res > 0) {

                    -- right;
                } else {
                    
                    result.push_back({ nums[i], nums[left], nums[right] });

                    while (left + 1 < nums.size() && nums[left] == nums[left + 1])
                        ++ left;
                    ++ left;
                    while (right - 1 >= 0 && nums[right] == nums[right - 1])
                        -- right;
                    -- right;
                }
            }

            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                ++ i;
            ++ i;
        }

        return result;
    }
};
