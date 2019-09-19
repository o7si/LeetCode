class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        const int Inf = 0x3F3F3F3F;
        int result = Inf;

        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size()) {

            int left = i + 1, right = nums.size() - 1;
            while (left < right) {

                int res = nums[i] + nums[left] + nums[right];
                if (abs(res - target) < abs(result - target))
                    result = res;

                if (res < target) {
                    
                    while (left + 1 < nums.size() && nums[left] == nums[left + 1])
                        ++ left;
                    ++ left;
                } else if (res > target) {
                    
                    while (right - 1 >= 0 && nums[right] == nums[right - 1])
                        -- right;

