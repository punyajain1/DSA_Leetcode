class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),m=0;
        vector<int> dp(n,1);
        vector<int> prev(n,-1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
            }
            if (dp[i] > dp[m]) m = i;
        }
        vector<int> ans;
        for(int i=m;i>=0;i=prev[i]){
            ans.push_back(nums[i]);
        }
        return ans;

    }
};