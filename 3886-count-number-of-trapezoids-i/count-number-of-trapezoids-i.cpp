class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int mod = 1e9 + 7;
        unordered_map<int, int> freq;
        for (const auto& p : points){
            freq[p[1]]++;
        }
        long long total = 0;
        long long pairs = 0;
        for (const auto& f : freq){
            if (f.second <= 1){
                continue;
            }
            long long pair = (long long)f.second * (f.second - 1) / 2;
            total += pair;
            pairs += pair * pair;
        }
        return (total * total - pairs) / 2 % mod;
    }
};