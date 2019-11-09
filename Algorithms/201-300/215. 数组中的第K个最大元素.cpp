class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, greater<int>> c;
        for (int i = 0; i < k; ++ i)
            c.push(nums[i]);
        for (int i = k; i < nums.size(); ++ i) {

            if (nums[i] > c.top()) {

                c.pop();
                c.push(nums[i]);
            }
        }
        return c.top();
    }
};
