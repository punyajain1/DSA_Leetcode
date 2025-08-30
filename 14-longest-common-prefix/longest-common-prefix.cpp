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
            int j=0;
            while(j<pre.size() && j<s1.size() && s1[j]==pre[j]){
                j++;
            }
            pre.erase(j);
        }
        if(pre.empty()) return "";
        return pre;
    }
};