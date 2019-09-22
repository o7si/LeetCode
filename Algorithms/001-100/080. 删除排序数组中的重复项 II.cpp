class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int insertPos = 0;
        for (int cur = 0; cur < nums.size(); ++ cur) {

            if (cur < 2 || nums[cur] != nums[insertPos - 2])
                nums[insertPos ++] = nums[cur];
        }
        return insertPos;
    }
};
