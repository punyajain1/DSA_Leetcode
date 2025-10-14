class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), a = 1, pi = 0, ml = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) a++;
            else {
                pi = a;
                a = 1;
            }
            ml = max(ml, max(a >> 1, min(pi, a)));
            if (ml >= k) return true;
        }
        return false;
    }
};