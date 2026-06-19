class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        if (n==0 || s[0]=='0') return 0;
        vector<int>dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            int a=s[i-1]-'0';
            int b = (s[i-2]-'0')*10 + (s[i-1]-'0');

            if(a<=9 && a>=1) dp[i]+=dp[i-1];
            if(b<=26 && b>=10) dp[i] += dp[i-2];
        }
        return dp[n];
    }
};