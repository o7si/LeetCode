class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int, size_t> hashmap;
        for (int i = 0; i < nums.size(); ++ i) {

            if (hashmap.find(nums[i]) != hashmap.end() && i - hashmap[nums[i]] <= k)
                return true;
            hashmap[nums[i]] = i;
        } 
        return false;
    }
};
