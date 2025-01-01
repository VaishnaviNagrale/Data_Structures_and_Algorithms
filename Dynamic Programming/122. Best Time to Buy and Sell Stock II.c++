class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2));
        dp[0][0] = -prices[0];
        dp[n][0] = dp[n][1] = 0;
        int profit = 0;
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j){
                    int take = -prices[i] + dp[i+1][0];
                    int nottake = dp[i+1][1];
                    profit = max(take,nottake);
                }else{
                    int sell = prices[i] + dp[i+1][1];
                    int notsell = dp[i+1][0];
                    profit = max(sell,notsell);
                }
                dp[i][j] = profit;
            }
        }
        return profit;
    }
};