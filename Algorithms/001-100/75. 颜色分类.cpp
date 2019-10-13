class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        // 红色（0） [0, i)
        // 白色（1） [i, j]
        // 蓝色（2） (j, size - 1]
        
        int i = 0, j = nums.size() - 1, k = 0;
        while (k <= j) {
            
            if (nums[k] == 0)
                swap(nums[k ++], nums[i ++]);
            else if (nums[k] == 1)
                ++ k;
            else if (nums[k] == 2)
                swap(nums[k], nums[j --]);
        }
    }
};
