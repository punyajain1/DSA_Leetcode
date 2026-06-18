class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        //as there are at minimum 1 way to reach 0 and 1 
        //dp[i] here i respesent ith step
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]; //this is to be done as - Last move was 1 step(either at 1 step back) or Last move was 2 steps (either we are 2 step back)
        }
        return dp[n];

    }
};