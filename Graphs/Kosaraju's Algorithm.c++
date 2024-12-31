
class DisjointSet
{
private:
    vector<int>rank,parent,size;
public:
    DisjointSet(int n);
    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u==ulp_v){
            return;
        }
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
    void unionBySize(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u==ulp_v){
            return;
        }
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]  = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v]  = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

DisjointSet::DisjointSet(int n)
{
    rank.resize(n+1,0);
    parent.resize(n+1);
    size.resize(n+1);
    for (int i = 0; i <=n; i++)
    {
        parent[i]=i;
        size[i] = 1;
    }
}
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node,vector<int>& vis,vector<vector<int>>& adj,stack<int>& st){
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            dfs(it,vis,adj,st);
	        }
	    }
	    st.push(node);
	}
	void dfsT(int node, vector<int>& vis, vector<vector<int>>& adjT) {
        vis[node] = 1;
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfsT(it, vis, adjT);
            }
        }
    }
    int kosaraju(int V, vector<vector<int>>& adj)
    {
         vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }

        vector<vector<int>> adjT(V);
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (auto &it : adj[i]) {
                // i -> it
                // it -> i
                adjT[it].push_back(i);
            }
        }
        int scc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                scc++;
                dfsT(node, vis, adjT);
            }
        }
        return scc;

    }
};