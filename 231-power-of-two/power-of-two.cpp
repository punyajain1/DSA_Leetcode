class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long x=1;
        while(x<=n){
            if(x==n) return true;
            x *= 2;
        }
        return false;
    }
};