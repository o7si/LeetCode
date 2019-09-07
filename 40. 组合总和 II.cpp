class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        search(candidates, target, 0, 0);
        return result;
    }
private:
    void search(vector<int>& nums, int target, int sum, int index) {

        if (sum == target) {

            result.push_back(tmp);
            return;
        }

        for (int i = index; i < nums.size(); ++ i) {

            if (sum + nums[i] > target)
                break;
            
            tmp.push_back(nums[i]);
            search(nums, target, sum + nums[i], i + 1);
            tmp.pop_back();

            int j = i + 1;
            while (j < nums.size() && nums[j] == nums[i])
                ++ j;
            i = j - 1;
        }
    }

    vector<vector<int>> result;
    vector<int> tmp;
};
