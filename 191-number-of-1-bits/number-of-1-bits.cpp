class Solution {
public:
    int hammingWeight(int n) {
        int c=0;
        while(n>=1){
            c++;
            n=n&(n-1);
        }
        return c;
    }
};