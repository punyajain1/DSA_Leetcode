class Solution {
public:
    int numSub(string s) {
        long long count = 0; 
        long long curr = 0;
        long long mod = 1e9 + 7;

        for (char c : s) {
            if (c == '1') {
                curr++;
            } else {
                count = (count + curr * (curr + 1) / 2) % mod;
                curr = 0;
            }
        }
        count = (count + curr * (curr + 1) / 2) % mod;
        return count;

    }
    
};