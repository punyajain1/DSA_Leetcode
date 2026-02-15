class Solution {
public:
    // int solve(int i,int j,string w1, string w2, vector<vector<int>>dp){
    //     if(i==0) return j;
    //     if(j==0) return i;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(w1[i-1]==w2[j-1]){
    //         return dp[i][j]= solve(i-1,j-1,w1,w2,dp);
    //     }else{
    //         int in=solve(i,j-1,w1,w2,dp);
    //         int del=solve(i-1,j,w1,w2,dp);
    //         int up=solve(i-1,j-1,w1,w2,dp);
    //         return dp[i][j]=min(up,min(del,in))+1;
    //     }
    // }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        //return solve(n,m,word1,word2 , dp);
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }
            }
        }
        return dp[n][m];
    }
};