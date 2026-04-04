class Solution {
public:
    bool isPalindrome(string s) {
        int r=s.length()-1;
        int l=0;
        while(r>=l) {
           if(!isalnum(s[l])){
               l++;
               continue;
           }
           if(!isalnum(s[r])){
               r--;
               continue;
           }
           if(tolower(s[r]) != tolower(s[l])){
               return false;
           }
           l++;
           r--;
        }
       return true;
    }
};