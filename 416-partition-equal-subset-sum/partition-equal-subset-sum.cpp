class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),t=0;
        if(n==1) return false;
        for(int i=0;i<n;i++){
            t+=nums[i];
        }
        if(t%2!=0) return false;
        //its prboblem is live if we can for the target which is equal to half of sum as we want to devide in 2 equal subset
        int t2=t/2;
        //dp knapsack problem either take it or leave it
        vector<vector<bool>> dp(n+1, vector<bool>(t2+1, false));
        for(int i=0;i<n;i++){
            //as all were target is 0 we can for the subset
            dp[i][0]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=t2;j++){
                
                //can we make j using nums[i-1](i starts from 1)
                if(nums[i-1]<=j){
                    dp[i][j] = ( dp[i-1][j] || dp[i-1][j-nums[i-1]] );
                }
                //if we cant
                else{
                    dp[i][j] = dp[i-1][j];
                }              
            }
        }
        //returning last element as the last will decide if its possible to make the partition of eqal subset sum 
        return dp[n][t2];
    }
};