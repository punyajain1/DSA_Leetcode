class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0;i<=n;i++){
            int a=i;
            int c=0;
            while(a>=1){
                a=a&(a-1);
                c++;
            }
            ans[i]=c;
        }
        return ans;
    }
};