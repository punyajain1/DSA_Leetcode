class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        int x = nums.size();
        for(int i=0; i<x ;i++){
            sum=sum+nums[i];
        }
        int sum2=(x+1)*(x)/2;
        return sum2-sum;
    }
};
