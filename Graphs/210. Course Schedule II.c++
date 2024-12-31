class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        //topo sort
        vector<int> adj[n];
        vector<int> indegree(n, 0);

        for (auto& it : prerequisites) {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int>ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        if (ans.size() == n) {
            return ans;
        }

        return {};
    }
};