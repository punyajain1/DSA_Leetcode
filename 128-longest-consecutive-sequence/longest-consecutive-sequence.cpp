class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int longest = 0;
        for(int num:st){
            if(st.find(num-1)==st.end()){
                int x = num;
                int cnt = 1;

                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x=x+1;
                }
                longest = max(longest,cnt);
            }
        }
        return longest;
    }
};