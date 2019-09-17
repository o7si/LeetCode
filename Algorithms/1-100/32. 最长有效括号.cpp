class Solution {
public:
    int longestValidParentheses(string s) {
        
        vector<pair<char, int>> c;
        
        c.push_back(make_pair(' ', -1));
        for (int i = 0; i < s.size(); ++ i) {
            
            if (c.empty() || !match((*--c.end()).first, s[i]))
                c.push_back(make_pair(s[i], i));
            else
                c.pop_back();
        }
        c.push_back(make_pair(' ', s.size()));
        
        int maxMatch = 0;
        for (int i = 0; i < c.size() - 1; ++ i)
            maxMatch = max(maxMatch, c[i + 1].second - c[i].second - 1);
            
        return maxMatch;
    }
private:
    bool match(char left, char right) {
        
        return left == '(' && right == ')';
    }
};
