class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        if(n==1) return 0;
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        int tf=0;
        for(int i=n-1;i>=0;i--){
            //no adjecent transection restriction
            //we will remove fee from finel profit after selling
            dp[i][1]=max(prices[i] -fee +dp[i+1][0] //sell (max of holding or selling after removing fee)
            ,dp[i+1][1] //hold
            );

            dp[i][0]=max(-prices[i] +dp[i+1][1] //buy
            ,dp[i+1][0] //skip
            );
        }

        return dp[0][0];
    }
};