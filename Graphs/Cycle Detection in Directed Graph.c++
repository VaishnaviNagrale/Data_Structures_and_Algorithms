class Solution {
  public:
//   Toposort Algorithm
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<int> indegree(V,0);
        for (int i = 0; i < V; ++i) {
            for (auto adjNode : adj[i]) {
                indegree[adjNode]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topoSort;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topoSort.push_back(node);
            for(auto adjNode:adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode]==0){
                    q.push(adjNode);
                }
            }
        }
        if(topoSort.size()!=V){
            return true;
        }
        return false;
    }
};