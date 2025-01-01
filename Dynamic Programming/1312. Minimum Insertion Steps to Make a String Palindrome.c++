class Solution {
public:
    int lcs(string X,string Y){
        int n=X.size();
        int m=Y.size();
        if(n==0 || m==0){
            return 0;
        }
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(X[i-1]==Y[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int minInsertions(string s1) {
        string s2(s1);
        reverse(s2.begin(),s2.end());
        return s1.size() - lcs(s1,s2);
    }
};