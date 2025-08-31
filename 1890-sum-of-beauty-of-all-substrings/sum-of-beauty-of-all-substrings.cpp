class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            unordered_map<char, int>mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                int maxf=0,minf=INT_MAX;
                for(auto it: mp){
                    maxf=max(maxf,it.second);
                    minf=min(minf,it.second);
                }
                ans+=(maxf-minf);
            }
        }
        return ans;
    }
};