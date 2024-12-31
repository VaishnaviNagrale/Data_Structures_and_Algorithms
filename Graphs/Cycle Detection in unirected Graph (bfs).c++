class Solution {
  public:
  bool bfs(int start,vector<vector<int>>& adj,vector<int>& vis){
        vis[start]=1;
        queue<pair<int,int>>q;
        q.push({start,-1});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int node=it.first;
            int parent=it.second;
            for(auto adjNode:adj[node]){
                if(!vis[adjNode]){
                    vis[adjNode]=1;
                    q.push({adjNode,node});
                }else if(adjNode!=parent){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(bfs(i,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};