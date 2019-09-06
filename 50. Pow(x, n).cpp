class Solution {
public:
    double myPow(double x, int n) {
     
        if (n >= 0)
            return quickPower(x, n);
        return 1 / quickPower(x, labs(n));
    }
private:
    double quickPower(double base, long n) {

        if (n == 0)
            return 1.0;
        
        double result = 1.0;
        while (n) {

            if (n & 1)
                result *= base;
            
            base *= base;
            n >>= 1;
        }
        return result;
    }
};
