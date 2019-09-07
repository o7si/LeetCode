class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
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
            search(nums, target, sum + nums[i], i);
            tmp.pop_back();
        }
    }

    vector<vector<int>> result;
    vector<int> tmp;
};
