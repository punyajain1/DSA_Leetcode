class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        vector<pair<int, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), [](pair<int,int>& a, pair<int,int>& b){return a.second < b.second;});
        int n=vec.size();
        for(int i=n-1;i>=n-k;i--){
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};