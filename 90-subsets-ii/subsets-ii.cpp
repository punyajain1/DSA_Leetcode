class Solution {
public:
    void sub(vector<vector<int>> &v, int i, vector<int> &ans, vector<int> &nums) {
        v.push_back(ans);
        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1]) continue;
            ans.push_back(nums[j]);
            sub(v, j + 1, ans, nums);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> ans;
        sort(nums.begin(), nums.end());
        sub(v,0,ans,nums);
        return v;

    }
};