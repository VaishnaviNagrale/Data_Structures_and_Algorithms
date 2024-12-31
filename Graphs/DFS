class Solution {
  public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& ans){
        vis[node]=1;
        ans.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,ans);
            }
        }
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> ans;
        vector<int> vis(n,0);
        dfs(0,adj,vis,ans);
        return ans;
    }
};
