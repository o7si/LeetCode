class Solution {
public:
    int divide(int dividend, int divisor) {

        bool negative = dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0;
        long result = ldivide(labs(dividend), labs(divisor));

        if (negative)
            result = -result;

        if (result < INT_MIN)
            return INT_MIN;
        if (result > INT_MAX)
            return INT_MAX;
        return result;
    }
private:
    long ldivide(long dividend, long divisor) {

        if (dividend < divisor)
            return 0;

        long multiple = 1;
        long sum = divisor;
        
        while (sum + sum <= dividend) {

            multiple = multiple + multiple;
            sum = sum + sum;
        }

        return multiple + ldivide(dividend - sum, divisor);
    }
};
