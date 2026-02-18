class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        if(n==1) return 0;
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        int tf=0;
        for(int i=n-1;i>=0;i--){
            //no adjecent transection restriction
            dp[i][0]=max(prices[i]-fee+dp[i+1][1] //sell
            ,dp[i+1][0] //hold
            );
            dp[i][1]=max(-prices[i]+dp[i+1][0] //buy
            , dp[i+1][1] //skip
            );
        }

        return dp[0][1];
    }
};