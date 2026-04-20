class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int n:nums){
            int i=abs(n)-1;
            if(nums[i]<0){
                return abs(n);
            }
            nums[i]*=-1;
        }
        return -1;
    }
    //here we are using org array as a hash
};