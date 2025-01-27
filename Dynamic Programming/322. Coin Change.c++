class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[n+1][amount+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=amount;j++){
                if(i==0 || j==0){
                    dp[i][j]=(j==0) ? 0 : INT_MAX-1;
                }
            }
        }
        for(int j=1;j<=amount;j++){
                if(j%coins[0]==0){
                    dp[1][j]=j;
                }
                else{
                    dp[1][j]=INT_MAX-1;
                }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){
                    dp[i][j]=min(dp[i][j-coins[i-1]]+1,dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        if(dp[n][amount]==INT_MAX-1){
            return -1;
        }
        return dp[n][amount];
    }
};