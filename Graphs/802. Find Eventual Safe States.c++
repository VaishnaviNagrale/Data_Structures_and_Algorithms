class Solution {
public:
    bool dfs(int i, vector<int>& visit, vector<int>& revisit, vector<int> adj[],
             vector<int>& check) {
        visit[i] = 1;
        revisit[i] = 1;

        for (auto child : adj[i]) {
            if (visit[child] == 0) {
                if (dfs(child, visit, revisit, adj, check) == true) {
                    return true;
                }
            } else if (visit[child] == 1 && revisit[child] == 1) {
                return true;
            }
        }

        check[i] = 1;

        revisit[i] = 0;

        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        // DFS
        // for (int i = 0; i < n; i++) {
        //     for (auto it : graph[i]) {
        //         int x = it;
        //         adj[i].push_back(x);
        //     }
        // }
        // vector<int> visit(n, 0);
        // vector<int> revisit(n, 0);
        // vector<int> check(n, 0);
        // vector<int> ans;

        // for (int i = 0; i < n; i++) {
        //     if (visit[i] == 0) {
        //         dfs(i, visit, revisit, adj, check);
        //     }
        // }

        // for (int i = 0; i < n; i++) {
        //     if (check[i] == 1) {
        //         ans.push_back(i);
        //     }
        // }

        // return ans;

        // BFS
        vector<int> indegree(n,0);
        for (int i = 0; i < n; i++) {
            for (auto it : graph[i]) {
                adj[it].push_back(i);
                indegree[i]++;
            }
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
        sort(ans.begin(),ans.end());
        return ans;
    }
};