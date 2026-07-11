class Solution {
public:
    int h[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }else{
                    mat[i][j]=INT_MAX;
                }
            }
        }
        while(!q.empty()){
            int a=q.front().first;
            int b=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int x=a+h[k][0];
                int y=b+h[k][1];
                if(x>=0 && x<m && y>=0 && y<n && mat[x][y]==INT_MAX){
                    mat[x][y]=mat[a][b]+1;
                    q.push({x,y});
                }
            }
        }
        return mat;
    }
};