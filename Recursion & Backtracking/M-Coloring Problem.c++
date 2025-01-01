class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(int node,vector<int>color,bool graph[101][101],int n,int col){
        for(int k=0;k<n;k++){
            if(k!=node && graph[k][node]==1 && color[k]==col){
                return 0;
            }
        }
        return 1;
    }
    bool solve(int node,vector<int>color,int m,int n,bool graph[101][101]){
        if(node==n){
            return 1;
        }
        for(int i=1;i<=m;i++){
            if(isSafe(node,color,graph,n,i)){
                color[node]=i;
                if(solve(node+1,color,m,n,graph)){
                    return 1;
                }else{
                    color[node]=0;
                }
            }
        }
        return 0;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int>color(n,0);
        if(solve(0,color,m,n,graph)){
            return 1;
        }
        return 0;
    }
};