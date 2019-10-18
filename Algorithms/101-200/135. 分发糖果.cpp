class Solution {
public:
    int candy(vector<int>& ratings) {
        
        vector<int> ivec(ratings.size(), 1);

        for (int i = 1; i < ratings.size(); ++ i)
            if (ratings[i] > ratings[i - 1])
                ivec[i] = max(ivec[i], ivec[i - 1] + 1);
                
        for (int i = ratings.size() - 1 - 1; i >= 0; -- i)
            if (ratings[i] > ratings[i + 1])
                ivec[i] = max(ivec[i], ivec[i + 1] + 1);

        int count = 0;
        for (int i = 0; i < ivec.size(); ++ i)
            count += ivec[i];
        return count;
    }
};
