class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt = 0;
        vector<int> v;
        int l=0,r=0 , z=0;
        while(r<nums.size()){
            if(nums[r]==0){
                z++;
            }
            if(z>k){
                if(nums[l]==0){
                    z--;
                }
                l++;
            }
            if(z<=k){
                cnt=max(cnt,r-l+1);
            }
            r++;
        }
        return cnt;
    }
};