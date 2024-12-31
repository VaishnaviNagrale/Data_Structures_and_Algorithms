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
    int removeStones(vector<vector<int>>& stones) {
        int n = 0;
        int m = 0;
        for (auto it : stones) {
            n = max(n, it[0]);
            m = max(m, it[1]);
        }
        int ans = 0;
        DisjointSet ds(n + m + 1);
        unordered_map<int, int> mp;
        for (auto it : stones) {
            int row = it[0];
            int col = it[1] + n + 1;
            ds.unionBySize(row, col);
            mp[row] = 1;
            mp[col] = 1;
        }
        int cnt = 0;
        for (auto itr : mp) {
            if (ds.findUPar(itr.first) == itr.first) {
                cnt++;
            }
        }
        ans = stones.size() - cnt;
        return ans;
    }
};