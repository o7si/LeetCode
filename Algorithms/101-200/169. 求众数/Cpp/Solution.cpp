class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++ i)
            ++ hash[nums[i]];

        int result = -1;
        for (const auto& elem : hash)  {
            
            if (elem.second > nums.size() / 2) {

                result = elem.first;
                break;
            }
        }
        return result;
    }
};
