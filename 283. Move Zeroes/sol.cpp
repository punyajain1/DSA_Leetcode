class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count =0;
        vector<int> t;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count++;
            }else{
                t.push_back(nums[i]);
            }
        }
        while(count--){
            t.push_back(0);
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=t[i];
        }
        
    }
};