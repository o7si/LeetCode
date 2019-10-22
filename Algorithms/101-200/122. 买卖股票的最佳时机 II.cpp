class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.empty())
            return 0;

        vector<vector<int>> dp(2, vector<int>(prices.size(), 0));
        for (int i = 0; i < prices.size(); ++ i) {

            if (i == 0) {

                dp[0][i] = 0;
                dp[1][i] = -prices[i];
            } else {

                dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i]);
                dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] - prices[i]);
            } 
        }
        return dp[0][prices.size() - 1];
    }
};
