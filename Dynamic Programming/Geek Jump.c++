class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        int ans=0;
        vector<int>dp(n,-1);
        dp[0]=0;
        for(int i=1;i<n;i++){
            int one = dp[i-1] + abs(height[i]-height[i-1]);
            int two = 1e9;
            if(i>=2){
                two = dp[i-2] + abs(height[i]-height[i-2]);
            }
            dp[i] = min(one,two);
        }
        return dp[n-1];
    }
};