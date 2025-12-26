class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int geq_k_count = 0, n = happiness.size();
        for (int x : happiness) {
            geq_k_count += x >= k;
        }

        if (geq_k_count >= k) {
            auto start = happiness.begin();
            std::nth_element(start, start + n - k, happiness.end());
            long long ans = 0;
            for (int i = 0; i < k; ++i) {
                ans += happiness[n - i - 1] - i;
            }
            return ans;
        }

        long long ans = 0, picked = 0;
        std::vector<int> count(k);
        for (int x : happiness) {
            if (x < k) {
                ++count[x];
            } else {
                ans += x - picked++;
            }
        }

        for (int i = k - 1; i >= picked; --i) {
            while (i >= picked && count[i]--) {
                ans += i - picked++;
            }
        }
        return ans;
    }
};