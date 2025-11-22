class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        for(auto it:nums){
            if(it%3==1 || it%3==2) ans++;
        }
        return ans;
    }
};