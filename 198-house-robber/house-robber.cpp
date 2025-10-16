class Solution {
public:
    int solve(int i,vector<int>& nums, vector<int>& dp){
        if(i<0) return 0;
        if(i==0) return nums[0];
        if(dp[i]!=-1) return dp[i];
        //here we are seeing if the summ till left adjacent is greater or the sum of current + till(i-2) is greater
        return dp[i] = max(solve(i-1,nums,dp),solve(i-2,nums,dp)+nums[i]);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];

        vector<int> dp(n+1,-1);
        return solve(n-1,nums,dp);
    }
};