class Solution {
public:
    int maxOperations(string s) {
        int x=0;
        int a=0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                a++;
            }else if(i>0 && s[i-1]=='1') {
                x+=a;
            }
        }
        
        return x;
    }
};