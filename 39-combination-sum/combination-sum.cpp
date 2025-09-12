class Solution {
public:
    void combi(vector<vector<int>> &v, vector<int>& candidates,int t, int i, vector<int>&ans ,int sum){
        if(t<0) return;
        if(t==0){
            v.push_back(ans);
            return;
        }
        if(sum==t) {
            v.push_back(ans);
            return;
        }
        if(i==candidates.size() || sum>t) return;
        ans.push_back(candidates[i]);
        combi(v,candidates,t,i,ans,sum+candidates[i]);
        ans.pop_back();
        combi(v,candidates,t,i+1,ans,sum);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> ans;
        combi(v,candidates,target,0,ans,0);
        return v;
    }
};