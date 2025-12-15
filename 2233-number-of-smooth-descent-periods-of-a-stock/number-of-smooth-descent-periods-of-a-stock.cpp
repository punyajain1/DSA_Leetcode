class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        vector<long long>dp(n,0);
        dp[0]=1;
        int j=0;
        for(int i=1;i<n;i++){
            if(prices[i]-prices[i-1]==-1){
                dp[i]=dp[i-1]+i-j+1;
            }else{
                dp[i]=dp[i-1]+1;
                j=i;
            }
        }
        return dp[n-1];
    }
};