class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        string pre=strs[0];
        string c="";
        for(int i=1;i<strs.size();i++){
            string s1=strs[i];
            for(int i=0;i<pre.size();i++){
                if(pre[i]==s1[i]){
                    continue;
                }else{
                    pre=pre.erase(i);
                    break;
                }
            }
        }
        if(pre.empty()) return "";
        return pre;
    }
};