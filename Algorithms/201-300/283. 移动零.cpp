class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        for (int i = 1, beg = 0; i < nums.size(); ++ i) {

            if (nums[i] == 0)
                continue;
            
            int j = beg;
            while (j < i && nums[j] != 0)
                ++ j;

            if (j < i) {

                swap(nums[i], nums[j]);
                ++ beg;
            }
        }
    }
};
