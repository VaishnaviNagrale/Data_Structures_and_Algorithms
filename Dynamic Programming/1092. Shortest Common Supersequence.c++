class Solution {
public:
    //Tabulation Approch
    string getLcs(string X,string Y,int n,int m){
        if(n==0 || m==0){
            return "";
        } 
		string ans;
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
					dp[i][j]=0;
				}
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
		int i=n,j=m;
		while(i>0 && j>0){
			if(X[i-1]==Y[j-1]){
				ans.push_back(X[i-1]);
				i--;
				j--;
			}
			else{
				if(dp[i-1][j] > dp[i][j-1]){
					i--;
				}
				else{
					j--;
				}
			}
		}
		reverse(ans.begin(),ans.end());
        return ans;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        string lcs = getLcs(str1,str2,str1.size(),str2.size());
        int i=0,j=0;
        string ans;
        for(char ch:lcs){
            while(str1[i]!=ch){
                ans+=str1[i];
                i++;
            }
            while(str2[j]!=ch){
                ans+=str2[j];
                j++;
            }
            ans+=ch;
            i++;
            j++;
        }
        ans += str1.substr(i) + str2.substr(j);
        return ans;
    }
};