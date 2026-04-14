class Solution {
public:
    int calc(vector<int>& piles, int x){
        int th=0;
        for(int i=0;i<piles.size();i++){
            th+=((long long)piles[i] + x - 1) / x;
        }
        return th;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int r=*max_element(piles.rbegin(),piles.rend());
        int l=1;
        while(l<r){
            int mid=l+(r-l)/2;
            int x=calc(piles,mid);
            if(x<=h){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return (int)l;
    }
};