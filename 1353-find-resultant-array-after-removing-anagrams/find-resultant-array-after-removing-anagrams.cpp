class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int t1=0;
        ans.push_back(words[t1]);
        for(int i=1;i<words.size();i++){
            string st=ans.back();
            sort(st.begin(),st.end());
            string t=words[i];
            sort(t.begin(),t.end());
            if(st==t){
                continue;
            }else{
                ans.push_back(words[i]);
                t1=i;
            }
        }
        return ans;
    }
};