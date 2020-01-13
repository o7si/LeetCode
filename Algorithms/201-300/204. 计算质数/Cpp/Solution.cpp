class Solution {
public:
    int countPrimes(int n) {
        
        if (n < 2)
            return 0;

        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        vector<int> prime;
        for (int i = 2, k = 0; i < n; ++ i) {

            if (isPrime[i])
                prime.push_back(i);
            for (int j = 0; j < prime.size() && i * prime[j] < n; ++ j) {
                
                isPrime[i * prime[j]] = false;
                if (i % prime[j] == 0)
                    break;
            }
        }
        return prime.size();
    }
};
