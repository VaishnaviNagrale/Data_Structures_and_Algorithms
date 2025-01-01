class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        for (int x = 0; x <= k; x++) {
            dp[0][1][x] = 0;
            dp[0][0][x] = 0;
        }
        int profit = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int x = 1; x <= k; x++) {
                for (int buy = 0; buy <= 1; buy++) {
                    if (buy) {
                        int buyid = -prices[i] + dp[i + 1][0][x];
                        int notbuyid = dp[i + 1][1][x];
                        profit = max(buyid, notbuyid);
                    } else {
                        int sell = prices[i] + dp[i + 1][1][x - 1];
                        int notsell = dp[i + 1][0][x];
                        profit = max(sell, notsell);
                    }
                    dp[i][buy][x] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};