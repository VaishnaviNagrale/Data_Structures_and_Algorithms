class Solution {
public:
    bool isSafe(int row,int col,vector<string> board,int n){
        int i=row,j=col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        row=i;
        col=j;
        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
        }
        col=j;
        while(row<n && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    // void solve(int col,vector<string>& board,vector<vector<string>>& ans,int n){
    //     if(col==n){
    //         ans.push_back(board);
    //         return;
    //     }
    //     for(int row=0;row<n;row++){
    //         if(isSafe(row,col,board,n)){
    //             board[row][col]='Q';
    //             solve(col+1,board,ans,n);
    //             board[row][col]='.';
    //         }
    //     }
    // }
    void solve(int col,vector<string>& board,vector<vector<string>>& ans,vector<int>& leftRow,vector<int>& upperDig,vector<int>& lowerDig,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftRow[row]==0 && upperDig[row+col]==0 && lowerDig[n-1 + col-row]==0){
                board[row][col]='Q';
                leftRow[row]=1 ;
                upperDig[row+col]=1;
                lowerDig[n-1 + col-row]=1;
                solve(col+1,board,ans,leftRow,upperDig,lowerDig,n);
                board[row][col]='.';
                leftRow[row]=0 ;
                upperDig[row+col]=0;
                lowerDig[n-1 + col-row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        // solve(0,board,ans,n);
        // return ans;
        vector<int> leftRow(n,0),upperDig(2*n-1,0),lowerDig(2*n-1,0);
        solve(0,board,ans,leftRow,upperDig,lowerDig,n);
        return ans;
    }
};