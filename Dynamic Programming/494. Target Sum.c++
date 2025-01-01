
class Solution {
public:
    int countSubsets(vector<int> &arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        for (int i = 0; i <= n; i++) {
            dp[i][0]=1;
        }
        for (int j = 1; j <= k; j++) {
            dp[0][j]=0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][k];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum_arr = 0;
        for (int i = 0; i < n; i++) {
            sum_arr += nums[i];
        }
        if(sum_arr<target || (target+sum_arr)%2!=0){
            return 0;
        }
        int sum_s1 = (sum_arr + target) / 2;
        if(sum_s1<0){
            return 0;
        }
        return countSubsets(nums, sum_s1);
    }    
};
