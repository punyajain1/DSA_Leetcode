class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> v1(128,0);
        vector<int> v2(128,0);
        for(auto it:s) v1[it]++;
        for(auto it:t) v2[it]++;
        for(int i=0;i<v1.size();i++){
            if(v1[i]!=v2[i]) return false;
        }
        return true;
    }
};