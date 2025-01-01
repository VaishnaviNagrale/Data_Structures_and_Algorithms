class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int maxi = 1, len = 0;
        vector<int> dp(n, 1);
        vector<int> hash(n, -1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                len = i;
            }
        }
        vector<int> ans;
        int k = len;
        while (k >= 0) {
            ans.push_back(nums[k]);
            k = hash[k];
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};