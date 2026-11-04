class Solution {
public:
    double myPow(double x, int n) {
        long long exponent = n;
        bool isNegative = exponent < 0;

        if (isNegative) {
            exponent = -exponent;
        }

        double result = 1.0;

        while (exponent > 0) {
            if (exponent & 1) {
                result *= x;
            }

            x *= x;
            exponent >>= 1;
        }

        return isNegative ? 1.0 / result : result;
    }
};