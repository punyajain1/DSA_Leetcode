class Solution {
public:
    int solve(int i ,vector<int>& nums,vector<int>& dp){
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(solve(i-1,nums,dp) , solve(i-2,nums,dp)+nums[i]);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> a1,a2;
        for(int i=0;i<n;i++){
            if(i!=0)a1.push_back(nums[i]);
            if(i!=n-1)a2.push_back(nums[i]);
        }
        int n1=a1.size() , n2=a2.size();
        vector<int>dp1(n1+1,-1) , dp2(n2+1,-1);
        return max(solve(n1-1,a1,dp1),solve(n2-1,a2,dp2));
    }
};