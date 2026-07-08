class Solution {
public:
    int h[4][2] = {{1, 0},{-1, 0},{0, 1},{0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int, int>> rt;
        int t=0;
        int cnt=0;
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    t++;
                }
                if(grid[i][j]==2){
                    rt.push({i,j});
                    t--;
                }
            }
        }
        while(!rt.empty()){
            int s=rt.size();
            while(s--){
                //yaha aaise dekho jaise initially 2 rotten the to dono ek saath karege naa apne adjacent ko rot ek ek min m 8 rot hue
                auto [i,j]=rt.front();
                rt.pop();
                for (int k = 0; k < 4; k++){
                    int x=i+h[k][0];
                    int y=j+h[k][1];
                    if(x>=0 && x<m && y>=0 && y<n && grid[x][y] == 1){
                        rt.push({x,y});
                        grid[x][y]=2;
                        t--;
                    }
                }
            }
            if(!rt.empty()) ans++;
        }
        return (t==0)? ans:-1;
    }
};