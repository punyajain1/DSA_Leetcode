class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int j = 1; j <= target; j++) {
            for (int num : nums) {
                if (j >= num) {
                    if (dp[j] <= INT_MAX - dp[j - num]) {
                        dp[j] += dp[j - num];
                    } else {
                        dp[j] = INT_MAX;
                    }
                }
            }
        }
        return (int)dp[target];
    }
};