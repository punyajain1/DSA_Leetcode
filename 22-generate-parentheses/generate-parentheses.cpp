class Solution {
public:
    vector<string> res;
    void rec(string & s,int open,int close){
        if((open + close) ==0){
            res.push_back(s);
            return;
        }
        if(open>0){
            s.push_back('(');
            rec(s,open-1,close);
            s.pop_back();
        }
        if(open<close){
            s.push_back(')');
            rec(s,open,close-1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        rec(s,n,n);
        return res;
    }
};