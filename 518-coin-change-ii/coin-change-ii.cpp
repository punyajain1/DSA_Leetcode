class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount + 1, 0);
        dp[0]=1;
        for(int coin:coins){
            if(coin==0) continue;
            for(int j=coin;j<=amount;j++){
                if(dp[j]<=INT_MAX-dp[j-coin]){
                    dp[j]+=dp[j-coin];
                }else{
                    dp[j]=INT_MAX;
                }
            }
        }
        return (int)dp[amount];
    }
};