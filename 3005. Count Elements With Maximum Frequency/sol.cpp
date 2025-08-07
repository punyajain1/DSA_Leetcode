class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int , int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int fx=0;
        for(auto it:m){
            if(it.second>fx){
                fx = it.second;
            }
        }
        int mx=0;
        for(auto it:m){
            if(it.second == fx){
                mx++;
            }
        }
        return fx*mx;

    }
};