class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length() , cnt=0;
        
        for(int i=0;i<n;i++){
            int x=i,y=i;
            while(x>=0 && y<n && s[x]==s[y]){
                x--,y++,cnt++;
            }
            x=i,y=i+1;
            while(x>=0 && y<n && s[x]==s[y]){
                x--,y++,cnt++;
            }

        }
        return cnt;
    }
};