class Solution {
  public:
    bool dfs(int node,int parent,vector<vector<int>>& adj,vector<int>& vis){
        vis[node]=1;
        for(auto adjNode:adj[node]){
            if(!vis[adjNode]){
                if(dfs(adjNode,node,adj,vis)==true){
                    return true;
                }
            }else if(adjNode!=parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,-1,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};