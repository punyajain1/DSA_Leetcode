class Solution {
public:
    vector<vector<int>> v;
    void sub(int i, vector<int> &ans, vector<int> &nums) {
        v.push_back(ans);
        
        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1]) continue; // skip duplicate
            ans.push_back(nums[j]); //push current in ans
            sub(j + 1, ans, nums); // moving to next recursion
            ans.pop_back(); //poping the pushed above 
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        sub(0,ans,nums);
        return v;

    }
};