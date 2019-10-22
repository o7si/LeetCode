class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int result = 0;
        int curMin = INT_MAX;
        for (int i = 0; i < prices.size(); ++ i) {

            if (prices[i] > curMin)
                result = max(result, prices[i] - curMin);

            curMin = min(curMin, prices[i]);
        }
        return result;
    }
};
