class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        map<int,int> mp;
        
        for(int i=0;i<n;i++){
            int rem = nums[i]%value;
            while(rem<0)rem+=value;
            mp[rem]++;
        }
        int i=0;
        while(true){
            int rem = i%value;
            if(mp[rem]<=0)
                return i;
            else
                mp[rem]--;
            i++;
        }
        return -1;
    }
};