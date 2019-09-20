class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        search(nums);
        return result;
    }
private:
    void search(vector<int>& nums, int pos = 0) {

        result.push_back(path);
        for (int i = pos; i < nums.size(); ++ i) {

            path.push_back(nums[i]);
            search(nums, i + 1);
            path.pop_back();

            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                ++ i;
        }
    }
    vector<vector<int>> result;
    vector<int> path;
};
