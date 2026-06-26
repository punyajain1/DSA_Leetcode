class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==1) return 0;
        // we will be mentaing a dp which contains the 2 column
        vector<vector<int>>dp(n+2,vector<int>(2,0));

        for(int i=n-1;i>=0;i--){
            //sell or hold at dp[i][0]
            dp[i][0]=max(prices[i] + dp[i+2][1] // we do i+2 as we can buy at adjacent day 
            , dp[i+1][0]);
            //buy or skip at dp[i][1]
            dp[i][1]=max(-prices[i] + dp[i+1][0] ,dp[i+1][1]);
        }
        return dp[0][1];
    }
};