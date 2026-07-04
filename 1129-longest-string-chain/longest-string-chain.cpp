class Solution {
public:
    bool static so(string a,string b){
        return a.size()<b.size();
    }
    bool solve(string a,string b){
        if(a.size()!=b.size()+1) return false;
        int i=0,j=0;
        while(i<a.size()){
            if(a[i]==b[j] && j<b.size()){
                i++;
                j++;
            }else{
                i++;
            }
        }
        if(i==a.size() && j==b.size()){
            return true;
        }else{
            return false;
        }
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),so);
        int n=words.size();
        vector<int> dp(n,1);
        int m=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(solve(words[i],words[j]) && dp[i] < dp[j]+1){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            m=max(m,dp[i]);
        }
        return m;
    }
};