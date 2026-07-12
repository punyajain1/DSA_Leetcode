class Solution {
public:
    int h[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans=0;
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                grid[i][0] = 2;
                q.push({i,0});
            }
            if(grid[i][n-1]==1){
                grid[i][n-1] = 2;
                q.push({i,n-1});
            }
        }
        for(int i=0;i<n;i++){
            if(grid[0][i]==1){
                grid[0][i] = 2;
                q.push({0,i});
            }
            if(grid[m-1][i]==1){
                grid[m-1][i] = 2;
                q.push({m-1,i});
            }
        }

        while(!q.empty()){
            int a=q.front().first , b=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int x=a+h[k][0];
                int y=b+h[k][1];
                if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==1){
                    grid[x][y]=2;
                    q.push({x,y});
                }
            }
        }
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++) {
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};