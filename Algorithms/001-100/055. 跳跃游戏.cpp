class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int edge = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            
            if (i > edge)
                break;

            edge = max(edge, i + nums[i]);
        }

        return edge >= nums.size() - 1;
    }
};
