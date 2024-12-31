class Solution {
  public:
  vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n=adj.size();
        
        vector<int>dist(n,1e9);
        dist[src]=0;
        queue<int>q;
        q.push(src);
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto adjNode:adj[node]){
                if(dist[node]+1<dist[adjNode]){
                    dist[adjNode]=1+dist[node];
                    q.push(adjNode);
                }
            }
        }
        
        for(int i = 0;i<n;i++) {
            if(dist[i] == 1e9) {
                dist[i] = -1; 
            }
        }
        return dist; 
    }
};