class Solution {
public:
    bool subsetSum(vector<int> arr,int k){
        int n=arr.size();
        int dp[n+1][k+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                if(i==0){
                    dp[i][j]=false;
                }
                if(j==0){
                    dp[i][j]=true;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                if(arr[i-1]<=j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][k];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return 0;
        }
        return subsetSum(nums,sum/2);
    }
};