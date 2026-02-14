class Solution {
public:
    string longestPalindrome(string s) {
        int l=0;
        int r=-1;
        string t = "#";
        for (char c:s) {
            t += c;
            t += "#";
        }
        int n=t.size();
        int c=0,ml=0;
        vector<int> p(n);
        for(int i=0;i<n;i++){
            int k;
            if(i>r){
                k=0;
            }else{
                int j=r-i+l;
                k=min(p[j],r-i);
            }
            while(i-k-1>=0 && i+k+1<n && t[i-k-1]==t[i+k+1]){
                k++;
            }
            p[i]=k;
            if(i+k>r){
                l=i-k;
                r=i+k;
            }
            if(k>ml){
                c=i;
                ml=k;
            }
        }
        int st=(c-ml)/2;
        return s.substr(st,ml);
    }
};