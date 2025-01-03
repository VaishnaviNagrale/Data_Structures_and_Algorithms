class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    int m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==-1){
                    matrix[i][j] = 1e9;
                }
                if(i==j){
                    matrix[i][j] = 0;
                }
            }
        }
    
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    matrix[i][j] = min(matrix[i][j],(matrix[k][j]+matrix[i][k]));
                }
            }
        }
    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1e9){
                    matrix[i][j] = -1;
                }
            }
        }
    }
};