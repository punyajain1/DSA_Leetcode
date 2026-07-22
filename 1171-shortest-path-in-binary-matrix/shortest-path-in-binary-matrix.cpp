class Solution {
public:
    int h[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{1,1},{1,-1},{-1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;
        if(n==1) return 1;
        vector<vector<int>>adj(n,vector<int>(n,INT_MAX));
        queue<pair<int , pair<int , int>>>q;
        adj[0][0]=1;
        q.push({1,{0,0}});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int d=temp.first;
            int r=temp.second.first;
            int c=temp.second.second;
            for(int i=0;i<8;i++){
                int r=temp.second.first + h[i][0];
                int c=temp.second.second + h[i][1];
                if(r<n && r>=0 && c<n && c>=0 && grid[r][c]==0 && d+1 < adj[r][c]){
                    adj[r][c]=d+1;
                    if(r==n-1 && c==n-1) return d+1;
                    q.push({d+1,{r,c}});
                }
            }
        }
        return -1;
    }
};