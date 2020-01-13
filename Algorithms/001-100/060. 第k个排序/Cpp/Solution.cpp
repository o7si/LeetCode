class Solution {
public:
    string getPermutation(int n, int k) {
        
        vector<int> fact(n, 0);
        fact[0] = 1;
        for (int i = 1; i < n; ++ i) 
            fact[i] = i * fact[i - 1];

        string result;
        int state = 0;
        int pos = 1;
        while (pos <= n) {

            int rank = ceil(k * 1.0 / fact[n - pos]);
            k -= fact[n - pos] * (rank - 1);

            int number = getNumberByRank(n, rank, state);
            result.push_back(number + '0');
            state |= 1 << number;

            ++ pos;
        } 
        return result;
    }
private:
    int getNumberByRank(int n, int rank, int state) {

        int cnt = 0;
        for (int i = 1; i <= n; ++ i) {

            if (state >> i & 1)
                continue;
            
            if (++ cnt == rank)
                return i;
        }
        return 0;
    }
};
