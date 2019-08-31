class Solution {
public:
    int romanToInt(string s) {
        
        map<char, int> m = {
            { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 }
        };
        
        vector<int> c(s.size() + 1, 0);
        int number = 0;
        for (int i = s.size() - 1; i >= 0; -- i) {
            
            if (m[s[i]] < c[i + 1])
                c[i] = -m[s[i]];
            else
                c[i] = m[s[i]];
            
            number += c[i];
        }
        
        for (int i = 0; i < s.size(); ++ i)
            cout << c[i] << " ";
        
        return number;
    }
};
