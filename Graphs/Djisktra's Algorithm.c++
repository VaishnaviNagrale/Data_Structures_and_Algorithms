class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});
        
        vector<int>dist(V,1e9);
        dist[S]=0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int node = it.second;
            for(auto itr:adj[node]){
                int v = itr[0];
                int ndis = itr[1];
                if(dis+ndis<dist[v]){
                    dist[v] = dis + ndis;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
};