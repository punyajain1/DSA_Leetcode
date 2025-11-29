class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int a=0;
        for(auto it:nums){
            a+=it;
        }
        return a%k;
    }
};