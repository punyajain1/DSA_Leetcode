class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,r=*max_element(nums.begin(),nums.end());
        if(nums.size()>threshold) return -1;
        while(l<=r){
            int mid=l+(r-l)/2, x=0;
            for(auto it:nums){
                x+= (it+mid-1)/mid;
            }
            if(x<=threshold){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};