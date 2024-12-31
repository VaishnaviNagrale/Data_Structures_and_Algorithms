class Solution {
public:
    bool bfs(int start,vector<vector<int>> graph,vector<int>& color){
        queue<int>q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto adjNodes:graph[node]){
                if(color[adjNodes]==-1){
                    color[adjNodes]=!color[node];
                    q.push(adjNodes);
                }else if(color[adjNodes]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool dfs(int node,vector<vector<int>> graph,vector<int>& color){
        for(auto adjNodes:graph[node]){
            if(color[adjNodes]==-1){
                color[adjNodes]=!color[node];
                int res = dfs(adjNodes,graph,color);
                if(res==false){
                    return false;
                }
            }else if(color[adjNodes]==color[node]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                // if(bfs(i,graph,color)==false){
                //     return false;
                // }
                color[i]=0;
                if(dfs(i,graph,color)==false){
                    return false;
                }
            }
        }
        return true;
    }
};