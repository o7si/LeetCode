class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        int i = 0;
        while (i < nums.size()) {

            int j = i + 1;
            while (j < nums.size()) {

                int left = j + 1;
                int right = nums.size() - 1;

                while (left < right) {
                    
                    int cur = nums[i] + nums[j] + nums[left] + nums[right];
                    if (cur < target) {
                        
                        while (left + 1 < right && nums[left + 1] == nums[left])
                            ++ left;
                        ++ left;
                    } else if (cur > target) {
                        
                        while (right - 1 > left && nums[right - 1] == nums[right])
                            -- right;
                        -- right;
                    } else {

                        result.push_back({ nums[i], nums[j], nums[left], nums[right] });
                        
                        while (left + 1 < right && nums[left + 1] == nums[left])
                            ++ left;
                        ++ left;
                        while (right - 1 > left && nums[right - 1] == nums[right])
                            -- right;
                        -- right;
                    }
                }

                while (j + 1 < nums.size() && nums[j + 1] == nums[j])
                    ++ j;
                ++ j;
            }

            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                ++ i;
            ++ i;
        }

        return result;
    }
};
