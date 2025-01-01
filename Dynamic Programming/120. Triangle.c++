class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if (i == triangle.size() - 1) {
            return dp[i][j] = triangle[i][j];
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int down = solve(i + 1, j, triangle, dp);
        int diagonal = solve(i + 1, j + 1, triangle, dp);
        return dp[i][j] = triangle[i][j] + min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solve(0, 0, triangle, dp);
        int dp[n][m];
        for(int j=0;j<m;j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[i][j] = triangle[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};
