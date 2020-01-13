class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        const int Len = 10;
        if (s.size() <= Len)
            return vector<string>();

        vector<string> result;
        unordered_map<string, int> hash;
        for (int i = 0; i <= s.size() - Len; ++ i) {

            string sub = s.substr(i, Len);
            if (hash[sub] == 1)
                result.push_back(sub);
            ++ hash[sub];
        }
        return result;
    }
};
