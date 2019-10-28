class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int> ugly;
        ugly.push_back(1);

        int i = 0, j = 0, k = 0;
        while (-- n) {

            int minValue = min(ugly[i] * 2, min(ugly[j] * 3, ugly[k] * 5));
            ugly.push_back(minValue);

            if (ugly[i] * 2 == minValue)
                ++ i;
            if (ugly[j] * 3 == minValue)
                ++ j;
            if (ugly[k] * 5 == minValue)
                ++ k;
        }

        return ugly.back();
    }
};
