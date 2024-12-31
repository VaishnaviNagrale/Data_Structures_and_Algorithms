class Solution {
public:
    void dfs(int sr, int sc, int color, int initialColor,
             vector<vector<int>> image, vector<vector<int>>& ans, vector<int> delRow,
             vector<int> delCol) {
        int n = image.size();
        int m = image[0].size();
        ans[sr][sc] = color;
        for (int i = 0; i < 4; i++) {
            int nrow = sr - delRow[i];
            int ncol = sc - delCol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                image[nrow][ncol] == initialColor && ans[nrow][ncol] != color) {
                dfs(nrow, ncol, color, initialColor, image, ans, delRow,
                    delCol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        vector<vector<int>> ans = image;
        int initialColor = image[sr][sc];
        vector<int>delRow = {-1, 0, 1, 0};
        vector<int>delCol = {0, 1, 0, -1};
        dfs(sr, sc, color, initialColor, image, ans, delRow, delCol);
        return ans;
    }
};