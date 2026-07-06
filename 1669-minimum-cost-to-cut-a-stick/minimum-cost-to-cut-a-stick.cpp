class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1,0));
        for(int i=m-2;i>=0;i--){
            for(int j=i+2;j<m;j++){
                dp[i][j] = INT_MAX;
                for(int k=i+1;k<j;k++){
                    dp[i][j]= min(dp[i][j],dp[i][k]+dp[k][j]+cuts[j]-cuts[i]);
                }
            }
        }
        return dp[0][m-1];
    }
};