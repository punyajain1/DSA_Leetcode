class Solution {
public:
    void make(vector<string>&v,string &d,string &ans,int i,vector<string> map){
        if(i==d.length()){
            v.push_back(ans);
            return;
        }
        int num=d[i]-'0';
        string c=map[num];
        for(int j=0;j<c.length();j++){
            ans.push_back(c[j]);
            make(v,d,ans,i+1,map);
            ans.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        if(digits.empty()) return v;
        string ans="";
        vector<string> mapp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        make(v,digits,ans,0,mapp);
        return v;
    }
};