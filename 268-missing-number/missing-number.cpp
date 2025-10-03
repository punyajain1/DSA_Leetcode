class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x=nums.size();
        int n=x;
        for(int i=0; i<x ;i++){
            n^= i^nums[i];
        }
        return n;
    }
};