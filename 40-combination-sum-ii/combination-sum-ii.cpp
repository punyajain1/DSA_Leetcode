class Solution {
public:
    void combi(vector<vector<int>> &v, vector<int>& candidates,int t, int i, vector<int>&ans){
        if(t==0) {
            v.push_back(ans);
            return;
        }
        for(int j = i; j < candidates.size(); j++) {
            if(j > i && candidates[j] == candidates[j-1]) continue;
            if(candidates[j] > t) break;
            ans.push_back(candidates[j]);
            combi(v, candidates, t - candidates[j], j + 1, ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> v;
        vector<int> ans;
        combi(v,candidates,target,0,ans);
        return v;
    }
};