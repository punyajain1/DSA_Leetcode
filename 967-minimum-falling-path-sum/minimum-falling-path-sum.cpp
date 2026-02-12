class Solution {
public:
    int solve(int i, int j , int n,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(j<0||j>=n) return INT_MAX;
        if(i==n-1) return grid[i][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int dl= solve(i+1,j-1,n,grid,dp);
        int d=solve(i+1,j,n,grid,dp);
        int dr=solve(i+1,j+1,n,grid,dp);
        return dp[i][j]=(grid[i][j]+min({dl,d,dr}));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            ans=min(ans,solve(0,i,n,matrix,dp));
        }
        return ans;

    }
};