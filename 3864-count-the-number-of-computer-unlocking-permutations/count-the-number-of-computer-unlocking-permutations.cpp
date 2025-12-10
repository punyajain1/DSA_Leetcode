class Solution {
public:
    const int MOD = 1e9+7;
    int countPermutations(vector<int>& complex) {
        int n = complex.size();
        int beg = complex[0];
        long long ans = 1;
        for(int i=1;i<n;i++){
            if(complex[i] <= beg) return 0;
            ans = (ans*i)%MOD;
        }
        return (int) ans;
    }
};