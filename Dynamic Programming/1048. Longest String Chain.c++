class Solution {
public:
    bool compare(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        if (n != m + 1){
            return false;
        }
        int i=0, j=0;
        while (i < n) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            } 
            else{
                i++;
            }
        }
        if (i == n and j == m){
            return true;
        }
        return false;
    }
    static bool cmp(string& s1,string& s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& nums) {
        sort(nums.begin(), nums.end(),cmp);
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (compare(nums[i], nums[j]) && 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};