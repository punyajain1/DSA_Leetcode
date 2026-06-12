class Solution {
public:
    vector<string> res;
    void rec(string & s,int o,int c){
        if((o+c)==0){
            res.push_back(s);
            return;
        }
        if(o>0){
            s.push_back('(');
            rec(s,o-1,c);
            s.pop_back();
        }
        if(o<c){
            s.push_back(')');
            rec(s,o,c-1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        rec(s,n,n);
        return res;
    }
};