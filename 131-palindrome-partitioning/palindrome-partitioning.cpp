class Solution {
public:
    bool palin(string ans,int l,int r){
        while(l<=r){
            if(ans[l]!=ans[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void sol(vector<vector<string>> &v,string &s, vector<string> &ans,int i){
        if(i == s.size()){
            v.push_back(ans);
            return;
        }

        for (int j=i;j<s.size();j++) {
            if(palin(s,i,j)){
                ans.push_back(s.substr(i,j-i+1));
                sol(v,s,ans,j+1);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> v;
        if(s.length()==0) return v;
        vector<string> ans;
        sol(v,s,ans,0);
        return v;

    }
};