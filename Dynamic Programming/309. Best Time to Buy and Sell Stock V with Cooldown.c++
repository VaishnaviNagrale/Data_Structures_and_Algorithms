class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        dp[n][0] = 0;
        dp[n][1] = 0;
        int profit = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    int buyid = -prices[i] + dp[i + 1][0];
                    int notbuyid = dp[i + 1][1];
                    profit = max(buyid, notbuyid);
                } else {
                    int sell = prices[i] + dp[i + 2][1];
                    int notsell = dp[i + 1][0];
                    profit = max(sell, notsell);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};