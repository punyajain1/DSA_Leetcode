class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(divisor == 1) return dividend;

        bool isPositive = (dividend >= 0) == (divisor >= 0);

        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        
        long long ans = 0;
        while(a >= b) {
            long long temp = b, multiple = 1;
            while(a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            ans += multiple;
        }

        ans = isPositive ? ans : -ans;
        if(ans > INT_MAX) return INT_MAX;
        if(ans < INT_MIN) return INT_MIN;
        return (int)ans;
    }
};
