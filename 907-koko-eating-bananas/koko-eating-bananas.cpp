class Solution {
public:
    long long calc(vector<int>& piles, int x){
        long long th=0;
        for(long long i=0;i<piles.size();i++){
            th += (piles[i] + x - 1) / x;
        }
        return th;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        long long n=piles.size();
        long long l=1,r=piles[n-1];
        while(l<=r){
            long long mid=(l+r)/2;
            long long x=calc(piles,mid);
            if(x<=h){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return (int)l;
    }
};