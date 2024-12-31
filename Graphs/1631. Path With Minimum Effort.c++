class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, -1, 0, 1};

        while (!pq.empty()) {
            auto it = pq.top();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();

            if (row == n - 1 && col == m - 1) {
                return dis;
            }

            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) {
                    int nwt =
                        max(dis, abs(heights[nrow][ncol] - heights[row][col]));
                    if (nwt < dist[nrow][ncol]) {
                        dist[nrow][ncol] = nwt;
                        pq.push({nwt, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};
