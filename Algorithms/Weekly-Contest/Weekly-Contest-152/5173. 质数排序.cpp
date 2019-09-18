class Solution {
public:
    int numPrimeArrangements(int n) {
        
        const long Mod = 1e9 + 7;
        
        int prime = 0;
        for (int i = 1; i <= n; ++ i)
            prime += isPrime(i);
        
        // res = prime! * (n - prime)!
        long res = 1;
        for (int i = 1; i <= prime; ++ i)
            res = (res * i) % Mod;
        for (int i = 1; i <= n - prime; ++ i)
            res = (res * i) % Mod;
        
        return res;
    }
private:
    bool isPrime(int num) {
        
        if (num == 0 || num == 1)
            return false;
        if (num == 2)
            return true;
        if (num % 2 == 0)
            return false;
        for (int i = 3; i <= sqrt(num); ++ i)
            if (num % i == 0)
                return false;
        return true;
    }
};
