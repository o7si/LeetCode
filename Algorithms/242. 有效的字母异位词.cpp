class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char, int> shash;
        unordered_map<char, int> thash;

        for (const auto sch : s)
            ++ shash[sch];
        for (const auto tch : t)
            ++ thash[tch];

        return shash == thash;
    }
};
