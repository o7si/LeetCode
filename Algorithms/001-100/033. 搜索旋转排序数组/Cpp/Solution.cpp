// 复杂度不满足 O(logn) 的要求
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int left = findPostion(nums);
        int right = left + nums.size() - 1;
        
        while (left <= right) {
            
            int mid = left + (right - left) / 2;
            if (target < nums[mid % nums.size()])
                right = mid - 1;
            else if (target > nums[mid % nums.size()])
                left = mid + 1;
            else
                return mid % nums.size();
        }
        
        return -1;
    }
private:
    int findPostion(vector<int>& nums) {
        
        for (int i = 1; i < nums.size(); ++ i)
            if (nums[i - 1] > nums[i])
                return i;
        return 0;
    }
};
