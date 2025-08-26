class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = 0, high = 0;
        for (int num : nums) {
            low = max(low, num);
            high += num;
        }
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isFeasible(nums, mid, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    
    bool isFeasible(vector<int>& nums, int ms, int k) {
        int c=1;
        int cs=0;
        for(auto it : nums){
            cs+=it;
            if(cs>ms){
                c++;
                cs=it;
                if(c>k) return false;
            }
        }
        return true;
    }
};