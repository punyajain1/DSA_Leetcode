class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(string s:strs){
            int x=count(s.begin(), s.end(), '0');
            int y=count(s.begin(), s.end(), '1');
            for (int i=m;i>=x;i--) {
                for (int j=n;j>=y;j--) {
                    dp[i][j]=max(dp[i][j],dp[i-x][j-y]+1);
                }
            }
        }
        return dp[m][n];
    }
};