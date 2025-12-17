class Solution{
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(3, vector<long long>(k+1, 0)));
        for(int K=1; K<=k; K++){
            dp[n-1][0][K] = 0;
            dp[n-1][1][K] = prices[n-1];
            dp[n-1][2][K] = -prices[n-1];
        }
        for(int idx=n-2; idx>=0; idx--){
            for(int state=0; state<3; state++){
                for(int cnt=1; cnt<=k; cnt++){
                    long long profit = 0;
                    if(state == 0){
                        profit = max({-prices[idx] + dp[idx+1][1][cnt], prices[idx] + dp[idx+1][2][cnt], dp[idx+1][0][cnt]});
                    }
                    else if(state == 1){
                        profit = max({prices[idx] + dp[idx+1][0][cnt-1], dp[idx+1][1][cnt]});
                    }
                    else {
                        profit = max({-prices[idx] + dp[idx+1][0][cnt-1], dp[idx+1][2][cnt]});
                    }
                    dp[idx][state][cnt] = profit;
                }
            }
        }
        return dp[0][0][k];
    }
};