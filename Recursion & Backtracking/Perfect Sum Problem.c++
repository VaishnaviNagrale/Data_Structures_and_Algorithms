class Solution{

	public:
	#define mod 1000000007
	int perfectSum(int arr[], int n, int sum)
	{
       vector<int>dp(sum+1,0);
       dp[0]=1;
       for(int i=0;i<n;i++){
           for(int j=sum;j>=arr[i];j--){
               dp[j]+=dp[j-arr[i]];
               dp[j]%=mod;
           }
       }
       return dp[sum];
	}
	  
};