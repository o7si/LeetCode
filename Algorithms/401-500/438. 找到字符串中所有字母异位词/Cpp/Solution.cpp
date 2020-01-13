class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        unordered_map<char, int> need;
        for (int i = 0; i < p.size(); ++ i)
            ++ need[p[i]];

        int left = 0, right = 0, match = 0;
        vector<int> result;

        unordered_map<char, int> window;
        while (right < s.size()) {

            if (need.find(s[right]) != need.end()) {

                ++ window[s[right]];
                if (window[s[right]] == need[s[right]])
                    ++ match;
            }
            ++ right;

            while (left < right && match == need.size()) {

                if (right - left == p.size()) 
                    result.push_back(left);

                if (need.find(s[left]) != need.end()) {

                    -- window[s[left]];
                    if (window[s[left]] < need[s[left]])
                        -- match;
                }
                ++ left;
            }
        }

        return result;
    }
};
