class Solution {
public:
    void s(int col,vector<vector<string>> &ans, vector<string> &board , vector<int> &leftR,vector<int> &lb,vector<int> &ub,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftR[row]==0 && lb[row+col]==0 && ub[n-1+col-row]==0){
                board[row][col]='Q';
                leftR[row]=1;
                lb[row+col]=1;
                ub[n-1+col-row]=1;
                s(col+1,ans,board,leftR,lb,ub,n);
                board[row][col]='.';
                leftR[row]=0;
                lb[row+col]=0;
                ub[n-1+col-row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> leftR(n,0), lb(2*n -1),ub(2*n -1);
        s(0,ans,board,leftR,lb,ub,n);
        return ans;
    }
};