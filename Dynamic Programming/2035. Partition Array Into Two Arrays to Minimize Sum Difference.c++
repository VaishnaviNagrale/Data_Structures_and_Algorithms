class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int sum_arr = 0;
        for (int i = 0; i < n; i++) {
            sum_arr += nums[i];
        }
        bool dp[n + 1][sum_arr + 1];
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 0; i <= sum_arr; i++) {
            dp[0][i] = false;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum_arr; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        int mini = 1e9;
        for (int j = 0; j <= sum_arr / 2; j++) {
            if (dp[n][j] == true) {
                mini = min(mini, abs((sum_arr - j) - j));
            }
        }
        return mini;
    }
};
