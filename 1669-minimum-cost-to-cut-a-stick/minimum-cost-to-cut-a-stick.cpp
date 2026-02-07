class Solution {
public:
    int solve(vector<vector<int>>&dp , int i, int j ,vector<int> &cuts){
        if (j-i<=1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k=i+1;k<j;k++){
            int temp = solve(dp,i,k,cuts)+solve(dp,k,j,cuts)+cuts[j]-cuts[i];
            mini = min(mini,temp);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        int a = solve(dp,0,m-1,cuts);
        return a;

    }
};