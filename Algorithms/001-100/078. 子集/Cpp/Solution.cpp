class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
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
        }
    }
    vector<vector<int>> result;
    vector<int> path;
};
