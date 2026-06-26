class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n][0]=0;
        dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j==0){
                    dp[i][j]=max(dp[i+1][0],-prices[i]+dp[i+1][1]);
                }else{
                    dp[i][j]=max(dp[i+1][1],prices[i]+dp[i+1][0]);
                }
            }
        }
        return dp[0][0];
    }
};