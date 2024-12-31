class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n);
    int findUPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) {
            return;
        }
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) {
            return;
        }
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

DisjointSet::DisjointSet(int n) {
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    size.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
}
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        // step 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int r = i + drow[k];
                        int c = j + dcol[k];
                        int curr = (i * n) + j;
                        if (r >= 0 && r < n && c >= 0 && c < n &&
                            grid[r][c] == 1) {
                            int ncurr = (r * n) + c;
                            ds.unionBySize(curr, ncurr);
                        }
                    }
                }else{
                    continue;
                }
            }
        }
        // step 2
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                set<int> st;
                if (grid[i][j] == 0) {
                    for (int k = 0; k < 4; k++) {
                        int r = i + drow[k];
                        int c = j + dcol[k];
                        if (r >= 0 && r < n && c >= 0 && c < n &&
                            grid[r][c] == 1) {
                            int ncurr = (r * n) + c;
                            st.insert(ds.findUPar(ncurr));
                        }
                    }
                    int cnt = 1;
                    for (auto it : st) {
                        cnt += ds.size[it];
                    }
                    maxi = max(maxi, cnt);
                }
            }
        }
        for(int i=0;i<n*n;i++){
            maxi = max(maxi,ds.size[ds.findUPar(i)]);
        }
        return maxi;
    }
};