// User function template for C++

class Solution{
    public:
    void solve(int i, int j, vector<vector<int>>& a, int n, const string& ds, vector<vector<int>>& vis, vector<string>& ans) {
       if (i == n - 1 && j == n - 1) {
        ans.push_back(ds);
        return;
    }

    if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1) {
        vis[i][j] = 1;
        solve(i + 1, j, a, n, ds + "D", vis, ans);
        vis[i][j] = 0;
    }

    if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1) {
        vis[i][j] = 1;
        solve(i, j - 1, a, n, ds + "L", vis, ans);
        vis[i][j] = 0;
    }

    if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1) {
        vis[i][j] = 1;
        solve(i, j + 1, a, n, ds + "R", vis, ans);
        vis[i][j] = 0;
    }

    if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1) {
        vis[i][j] = 1;
        solve(i - 1, j, a, n, ds + "U", vis, ans);
        vis[i][j] = 0;
    }
}

vector<string> findPath(vector<vector<int>>& a, int n) {
    vector<string> ans;
    if (a[0][0] == 1) {
        vector<vector<int>> vis(n, vector<int>(n, 0));
        string ds = "";
        solve(0, 0, a, n, ds, vis, ans);
    }
    return ans;
}

};