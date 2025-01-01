class Solution {
public:
    int solve(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
        if (i >= j) {
            return 0;
        }
        if (dp[i][j] != 0) {
            return dp[i][j];
        }
        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            int temp = arr[j] - arr[i - 1] + solve(arr, i, k, dp) +
                       solve(arr, k + 1, j, dp);
            ans = min(ans, temp);
        }
        return dp[i][j] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();

        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        return solve(cuts, 1, m - 1, dp);
    }
};
