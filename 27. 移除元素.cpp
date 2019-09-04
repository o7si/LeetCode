class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int count = 0;
        for (int i = 0, j = nums.size() - 1; i <= j; ++ i) {
            
            if (nums[i] == val) {
                
                swap(nums[i --], nums[j --]);
                ++ count;
            }
        }
        
        return nums.size() - count;
    }
};
