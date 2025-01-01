class Solution {
public:
    //Recursive
    // int solve(int n,vector<int> nums){
    //     if(n==0){
    //         return nums[n];
    //     }
    //     if(n<0){
    //         return 0;
    //     }
    //     int pick = nums[n];
    //     if(n>1){
    //        pick += solve(n-2,nums);
    //     }
    //     int notpick = solve(n-1,nums);
    //     return max(pick,notpick);
    // }
    // int solve(int n,vector<int> nums,vector<int>&dp){
    //     if(n==0){
    //         return nums[n];
    //     }
    //     if(n<0){
    //         return 0;
    //     }
    //     if(dp[n]!=-1){
    //         return dp[n];
    //     }
    //     int pick = nums[n];
    //     if(n>1){
    //        pick += solve(n-2,nums,dp);
    //     }
    //     int notpick = solve(n-1,nums,dp);
    //     return dp[n]=max(pick,notpick);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // return solve(n-1,nums);

        //Memoization
        // vector<int>dp(n+1,-1);
        // return solve(n-1,nums,dp);

        //Tabulation
        // vector<int>dp(n,0);
        // dp[0]=nums[0];
        // for(int i=1;i<n;i++){
        //     int pick = nums[i];
        //     if(i>1){
        //         pick += dp[i-2];
        //     }
        //     int notpick = dp[i-1];
        //     dp[i] = max(pick,notpick);
        // }
        // return dp[n-1];

        //Space optimization
        if(n==0){
            return nums[n];
        }
        if(n<0){
            return 0;
        }
        int prev1 = nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i>1){
                pick += prev2;
            }
            int notpick = prev1;
            int curr = max(pick,notpick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};