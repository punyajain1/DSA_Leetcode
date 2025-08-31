class Solution {
public:
    int maxDepth(string s) {
        int c=0;
        int mx=0;
        for(char i: s){
            if(i=='('){
                c++;
                mx=max(mx,c);
            }else if(i==')'){
                c--;
            }
        }
        return mx;
        
    }
};