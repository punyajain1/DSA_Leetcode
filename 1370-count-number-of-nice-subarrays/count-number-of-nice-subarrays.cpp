class Solution {
public:
    int sol(vector<int>& nums, int goal) {
        if(goal<0) return 0;
        int cnt=0;
        int l=0,s=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]%2==1){
                s++;
            }
            while(s>goal){
                if(nums[l]%2==1){
                    s--;
                }
                l++;
            }
            cnt+=r-l+1;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return sol(nums,k)-sol(nums,k-1);
    }
};