class Solution {
  public:
    string print_longest_common_subsequences(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n==0 || m==0){
            return "";
        } 
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int len = dp[n][m];
        int i = n;
        int j = m;
        
        int index = len - 1;
        string str = "";
        for (int k = 1; k <= len; k++) {
            str += "$";
        }
        
        while (i > 0 && j > 0) {
            if (s[i - 1] == t[j - 1]) {
                str[index] = s[i - 1];
                index--;
                i--;
                j--;
            } else if (s[i - 1] > t[j - 1]) {
              i--;
            } else j--;
        }
        return str;
    }
};