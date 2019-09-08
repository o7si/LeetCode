class Solution {
public:
    int jump(vector<int>& nums) {

        int step = 0, able = 0;
        int edge = 0;

        for (int index = 0; index < nums.size() - 1; ++ index) {

            able = max(able, index + nums[index]);
            if (index == edge) {

                edge = able;
                ++ step;
            }
        }

        return step;
    }
};
