class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            vector<int> mp(26,0);
            for(int j=i;j<n;j++){
                mp[s[j]-'a']++;
                int maxf=0;
                int minf=INT_MAX;
                for(auto it: mp){
                    if(it>0){
                        maxf=max(maxf,it);
                        minf=min(minf,it);
                    }
                }
                ans+=(maxf-minf);
            }
        }
        return ans;
    }
};