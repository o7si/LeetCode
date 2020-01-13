class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char, int> need;
        for (int i = 0; i < t.size(); ++ i)
            ++ need[t[i]];

        int left = 0, right = 0, match = 0;
        int start = -1, minLen = INT_MAX;

        unordered_map<char, int> window;
        while (right < s.size()) {

            if (need.find(s[right]) != need.end()) {

                ++ window[s[right]];
                if (window[s[right]] == need[s[right]])
                    ++ match;
            }
            ++ right;

            while (left < right && match == need.size()) {

                if (right - left < minLen) {

                    start = left;
                    minLen = right - left;
                }

                if (need.find(s[left]) != need.end()) {

                    -- window[s[left]];
                    if (window[s[left]] < need[s[left]])
                        -- match;
                }
                ++ left;
            }
        }

        return start == -1 ? "" : s.substr(start, minLen);
    }
};
