class Solution {
public:
int maxa(vector<int>& nums){
    int ans=INT_MIN;
    for(auto it:nums){
        ans=max(it,ans);
    }
    return ans;
}
int sumd(vector<int>& nums , int d){
    int ans=0;
    for(auto it:nums){
        ans+= ceil((double)it/double(d));
    }
    return ans;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,r=maxa(nums);
        if(nums.size()>threshold) return -1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int x=sumd(nums ,mid);
            if(x<=threshold){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};