class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int cmi=1,cma=1;
        for(int num: nums){
            int t=cma*num;
            cma=max(max(t, num*cmi), num);
            cmi=min(min(t, num*cmi), num);
            ans=max(ans,cma);
        }
        return ans;
    }
};