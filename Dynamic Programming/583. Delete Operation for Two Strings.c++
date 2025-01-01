class Solution {
public:
    //Tabulation Approch
    int lcs(string X,string Y){
        int n = X.size();
        int m = Y.size();
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
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int deletionCnt = word1.size() - lcs(word1,word2);
        int insertionCnt = word2.size() - lcs(word1,word2);
        return deletionCnt + insertionCnt;
    }
};