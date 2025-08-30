class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> m1(200,0),m2(200,0);
        for(int i=0;i<s.length();i++){
            if(m1[s[i]] != m2[t[i]]) { // here we are using char as the index for the m1 and m2 as the can store all the ined of all ascii char , char is coverted into its ascii int so that we can use it 
                return false;
            }
            m1[s[i]] = i+1;
            m2[t[i]] = i+1;
        }

        return true;
        
    }
};