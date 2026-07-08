class Solution {
public:
    int h[4][2] = {{1, 0},{-1, 0},{0, 1},{0, -1}};// checking in all direction up,down,left,right
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0') return; // this used while checking when we recursively called dfs  
        grid[i][j]='0';
        for (int k = 0; k < 4; k++) {
            dfs(grid, i+ h[k][0], j+h[k][1]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    dfs(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};