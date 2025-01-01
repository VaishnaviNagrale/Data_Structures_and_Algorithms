class Solution {
  public:
    int lcss(string X,string Y,int n,int m){
        if(n==0 || m==0){
            return 0;
        } 
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j]=0;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(X[i-1]==Y[j-1]){
                    int val=1+dp[i-1][j-1];
                    dp[i][j]=val;
                    ans=max(ans,val);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return ans;
    }
    int longestCommonSubstr(string& s1, string& s2) {
        return lcss(s1,s2,s1.size(),s2.size());
    }
};