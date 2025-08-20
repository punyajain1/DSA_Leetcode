class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 1;
        if(nums.empty()) return 0;
        unordered_set<int> s(nums.begin(),nums.end());
        for(auto it:s){
            if(s.find(it-1) == s.end()){
                int count=1;
                int x=it;
                while(s.find(x+1)!=s.end()){
                    x++;
                    count++;
                }
                longest=max(longest,count);
            }
        }
        return longest;
    }
};