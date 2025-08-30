class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()==0|| t.size()==0){
            return "";
        }
        vector<int> need(128,0);
        for(auto it : t){
            need[it]++;
        }
        int count=t.size();
        int l=0,r=0,d=INT_MAX,head=0;
        while(r < s.size()){
            if(need[s[r]]-->0) count--;
            r++;
            
            while(count == 0){
                if(r-l < d){
                    head=l;
                    d=r-head;
                }if(need[s[l]]++ == 0) count++;
                l++;
            }
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};