class Solution {
  public:
//   Kahn's Algorithm 
  vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> indegree(n,0);
        for (int i = 0; i < n; ++i) {
            for (auto adjNode : adj[i]) {
                indegree[adjNode]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
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
        return topoSort;
    }
};