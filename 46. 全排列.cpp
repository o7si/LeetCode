class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        search(nums, 0);
        return result;
    }
private:
    void search(vector<int>& nums, int state) {

        if (tmp.size() >= nums.size()) {
            
            result.push_back(tmp);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++ i) {
            
            if (state >> i & 1)
                continue;
            
            tmp.push_back(nums[i]);
            search(nums, state | 1 << i);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> result;
    vector<int> tmp;
};
