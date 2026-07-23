class Solution {
public:
    int h[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>> adj(n, vector<int>(m, INT_MAX));
        // pushing abs_diff,row,col of a node into queus
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;
        adj[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto temp= pq.top();
            pq.pop();
            int d=temp.first;
            int r=temp.second.first;
            int c=temp.second.second;
            if(r==n-1 && c==m-1) return d;
            for(int i=0;i<4;i++){
                int nr= r+h[i][0];
                int nc= c+h[i][1];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int a=max(d,abs(heights[r][c]-heights[nr][nc]));
                    if(a<adj[nr][nc]){
                        adj[nr][nc]=a;
                        pq.push({a,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};