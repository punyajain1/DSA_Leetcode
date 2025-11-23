class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);
        for (int x : nums) {
            vector<int> cur(dp);
            for (int r=0; r<3; r++) {
                int sum= dp[r] + x;
                cur[sum%3]=max(cur[sum%3],sum);
            }
            dp = cur;
        }
        return dp[0];
    }
};