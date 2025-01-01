class Solution {
public:
    int solve(int i, bool buy, int x, vector<int> prices,
              vector<vector<vector<int>>> dp) {
        int n = prices.size();
        if (x == 0) {
            return 0;
        }
        if (i == n) {
            return 0;
        }
        if (dp[i][buy][x] != -1) {
            return dp[i][buy][x];
        }
        int profit = 0;
        if (buy) {
            int buyid = -prices[i] + solve(i + 1, 0, x, prices, dp);
            int notbuyid = solve(i + 1, 1, x, prices, dp);
            profit = max(buyid, notbuyid);
        } else {
            int sell = prices[i] + solve(i + 1, 1, x - 1, prices, dp);
            int notsell = solve(i + 1, 0, x, prices, dp);
            profit = max(sell, notsell);
        }
        return dp[i][buy][x] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int x = 0; x <= 2; x++) {
            dp[0][1][x] = 0;
            dp[0][0][x] = 0;
        }
        int profit = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int x = 1; x <= 2; x++) {
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
        return dp[0][1][2];
    }
};
