class Solution {
public:
    int minimumOneBitOperations(int n) {
        vector<long long>v(31, 0);
        v[0] = 1;
        for(int i=1; i<31; i++){
            v[i] = (2*v[i-1])+1;
        }
        int cnt=0, ans=0;
        for(int i=30; i>=0; i--){
            if( (1<<i)&n ){
                cnt++;
                if(cnt%2)ans+=v[i];
                else ans-=v[i];
            }
        }
        return ans;
    }
};