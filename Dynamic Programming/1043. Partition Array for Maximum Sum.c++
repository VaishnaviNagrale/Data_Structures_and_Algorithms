class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            int maxElement = INT_MIN;
            for (int len = 1; len <= k && i - len >= 0; ++len) {
                maxElement = max(maxElement, arr[i - len]);
                dp[i] = max(dp[i], dp[i - len] + maxElement * len);
            }
        }

        return dp[n];
    }
};