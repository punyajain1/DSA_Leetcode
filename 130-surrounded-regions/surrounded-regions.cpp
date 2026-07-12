class Solution {
public:
    int h[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                board[i][0] = '#';
                q.push({i,0});
            }
            if(board[i][n-1]=='O'){
                board[i][n-1] = '#';
                q.push({i,n-1});
            }
        }
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                board[0][i] = '#';
                q.push({0,i});
            }
            if(board[m-1][i]=='O'){
                board[m-1][i] = '#';
                q.push({m-1,i});
            }
        }

        while(!q.empty()){
            int a=q.front().first , b=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int x=a+h[k][0];
                int y=b+h[k][1];
                if(x>=0 && x<m && y>=0 && y<n && board[x][y]=='O'){
                    board[x][y] = '#';
                    q.push({x,y});
                }
            }
        }
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++) {
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='#') board[i][j]='O';
            }
        }
    }
};