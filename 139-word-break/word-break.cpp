class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> possible(n+1,false);
        possible[n] = true;
        for(int i= n-1;i>=0;i--){
            for(auto word:wordDict){
                int x = word.size();
                if( i + x <= n && (s.substr(i,x)== word)){
                    possible[i] = possible[i+x];
                }
                if(possible[i]){
                    break;
                }
            }
        }
        return possible[0];
    }
};