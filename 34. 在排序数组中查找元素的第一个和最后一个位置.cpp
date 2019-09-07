class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int left = searchLeft(nums, target);
        int right = searchRight(nums, target);

        if (left <= right)
            return { left, right };
            
        return { -1, -1 };
    }
private:
    int searchLeft(vector<int>& nums, int target) {

        int left = 0, right = nums.size() - 1;
        while (left <= right) {

            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] >= target)
                right = mid - 1;
        }
        return left;
    }    

    int searchRight(vector<int>& nums, int target) {

        int left = 0, right = nums.size() - 1;
        while (left <= right) {

            int mid = left + (right - left) / 2;
            if (nums[mid] <= target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
        }
        return right;
    }
};
