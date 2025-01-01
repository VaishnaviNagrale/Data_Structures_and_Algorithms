class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }

        double result = 1.0;
        long long pow = n;

        if (pow < 0) {
            x = 1 / x;
            pow = -pow;
        }

        while (pow > 0) {
            if (pow % 2 == 1) {
                result *= x;
            }
            x *= x;
            pow /= 2;
        }

        return result;
    }
};
