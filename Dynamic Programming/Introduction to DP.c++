class Solution {
  public:
    long long int mod=1e9+7;
    long long int fib(int n, vector<long long int> &dp){
        if(n <= 1) {
            return n;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = ((fib(n-1,dp))%mod + (fib(n-2, dp))%mod)%mod;
    }
  
    long long int topDown(int n) {
        vector<long long int> dp(n+1,-1);
        return fib(n,dp);
    }
    
    long long int bottomUp(int n) {
        vector<long long int> dp(n+1,-1);
        dp[0] = 0, dp[1] = 1;
        for(long long int i=2;i<=n;i++){
            dp[i] = ((dp[i-1]%mod) + (dp[i-2]%mod))%mod;
        }
        return dp[n];
    }
};