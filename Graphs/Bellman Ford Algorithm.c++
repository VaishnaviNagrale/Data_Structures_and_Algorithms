class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int>dist(V,1e8);
        dist[S]=0;
        for(int i=1;i<V;i++){
            for(int j=0;j<edges.size();j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
                if(dist[u]+w<dist[v] && dist[u] != 1e8){
                    dist[v] = w + dist[u];
                }
            }
        }
        for(int j=0;j<edges.size();j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if(dist[u]+w<dist[v] && dist[u]!=1e8){
                return {-1};
            }
        }
        return dist;
    }
};