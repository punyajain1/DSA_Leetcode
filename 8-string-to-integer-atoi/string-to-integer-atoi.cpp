class Solution {
public:
    int myAtoi(string s) {
        long long ans=0;
        int sign=1,i=0,n=s.size();
        while(isspace(s[i]) && i<n) i++;
        if(s[i]=='-')
        {
            sign=-1;
            i++;
        }else if(s[i]=='+')i++;
        while(i<n && isdigit(s[i])){
            int d=s[i]-'0';
            ans=ans*10+d;
            if(ans>INT_MAX && sign==-1) return INT_MIN;
            else if(ans>INT_MAX && sign==1) return INT_MAX;
            i++;
        }
        return (int)ans*sign;
    }
};