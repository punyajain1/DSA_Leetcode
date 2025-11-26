class Solution {
public:
   
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k,0)));
        dp[0][0][grid[0][0]%k]++;
        int sum=grid[0][0];
        for(int i=1;i<m;i++){
            dp[0][i][(grid[0][i]+sum)%k]++;
            sum+=grid[0][i];
            
        }
        sum=grid[0][0];
        for(int i=1;i<n;i++){
            dp[i][0][(grid[i][0]+sum)%k]++;
            sum+=grid[i][0];
        }
         int mod=1000000007;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                int r= grid[i][j]%k;
                for(int l=0;l<k;l++){
                    dp[i][j][(r+l)%k]= (dp[i-1][j][l]%mod + dp[i][j-1][l]%mod)%mod;
                }
            }
        }
        return dp[n-1][m-1][0];
    }
};