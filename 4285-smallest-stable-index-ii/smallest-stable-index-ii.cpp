class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> a(n), b(n);
        a[0] = nums[0];
        b[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            a[i] = max(a[i-1], nums[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            b[i] = min(b[i + 1], nums[i]);
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int l = a[i];
            int r = b[i];
            if ((long long)l - (long long)r <= k) {
                ans=min(ans,i);
            }
        }
        if(ans!=INT_MAX) return ans;
        else return -1;
    }
};