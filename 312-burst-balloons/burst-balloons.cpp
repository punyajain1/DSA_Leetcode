class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int m=nums.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1,0));
        for(int i=m-2;i>=0;i--){
            for(int j=i+2;j<m;j++){
                dp[i][j] = INT_MIN;
                for(int k=i+1;k<j;k++){
                    dp[i][j]= max(dp[i][j],dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j]);
                }
            }
        }
        return dp[0][m-1];
    }
};