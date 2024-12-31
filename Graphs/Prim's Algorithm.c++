class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
          typedef pair<int,int>p;
          priority_queue<p,vector<p>,greater<p>>pq;
          vector<int>vis(V,0);
          pq.push({0,0}); // {dis,node}
          int sum =0;
          while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int node = it.second;
            if(vis[node]==1){
              continue;
            }
            vis[node]=1;
            sum+=dis;
            for(auto itr:adj[node]){
              int v = itr[0];
              int ndis = itr[1];
              if(!vis[v]){
                pq.push({ndis,v});
              }
            }
          }
          return sum;
    }
};