class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n=arr.size();
        int dp[n+1][target+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=target;j++){
                if(i==0){
                    dp[i][j]=false;
                }
                if(j==0){
                    dp[i][j]=true;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if(arr[i-1]<=j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    }
};