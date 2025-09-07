class Solution {
public:
    long long Pow(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = (n+1)/2;
        long long mod = pow(10,9)+7;
        return (Pow(5,even,mod) * Pow(4,odd,mod)) % mod;
    }
};