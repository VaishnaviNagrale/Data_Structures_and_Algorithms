class Solution {
public:
    bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            ++i;
            --j;
        }
        return true;
    }

    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> cuts(n, 0);

        for (int i = 0; i < n; ++i) {
            cuts[i] = i;
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (i - j <= 1 || dp[j + 1][i - 1])) {
                    dp[j][i] = 1;
                    if (j == 0) {
                        cuts[i] = 0;
                    } else {
                        cuts[i] = min(cuts[i], cuts[j - 1] + 1);
                    }
                }
            }
        }
        return cuts[n - 1];
    }
};