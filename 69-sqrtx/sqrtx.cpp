class Solution {
public:
    int mySqrt(int x) {
        if(x==1){
            return 1;
        }
        long long l=0,h=x/2;
        long long ans;
        while(l<=h){
            long long mid=(l+h)/2;
            if((mid*mid)<=x){
                ans = mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }
};