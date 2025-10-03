class Solution {
public:
    int reverse(int x) {
        long r=0;
        while(x!=0){
            int t=x%10;
            r=(r*10)+t;
            x=x/10;
        }
        if(r<INT_MIN || r>INT_MAX){
            return 0;
        }else{
            return r;
        }
        
    }
};