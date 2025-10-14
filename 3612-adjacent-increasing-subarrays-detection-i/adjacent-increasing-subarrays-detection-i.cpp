class Solution {
public:
   
bool check(vector<int>& nums, int start, int k) {
    for (int i=start+1;i<start+k;i++) {
        if(nums[i]<=nums[i-1]) return false;
    }
    return true;
}

bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    for (int i=0;i<=n-2*k;i++){
        if(check(nums,i,k)&&check(nums,i+k,k)){
            return true;
        }
    }
    return false;
}
};