class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int p=0,ne=1;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                ans[ne]=nums[i];
                ne+=2;
            }else{
                ans[p]=nums[i];
                p+=2;
            }
        }
        return ans;
    }
};