class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (auto ch : s) {
            freq[ch]++;
        }
        vector<pair<char, int>> v;
        for (auto it : freq) {
            v.push_back({it.first, it.second});
        }
       sort(v.begin(),v.end(),[](auto &a, auto &b) {
            return a.second > b.second;
        });
       string ans="";
       for(auto &it:v){
        while(it.second--){
            ans.push_back(it.first);
        }
       }
       return ans;
    }
};