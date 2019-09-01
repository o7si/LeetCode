class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        if (digits.empty())
            return vector<string>();
        
        map<int, string> phone = {
                           { 2, "abc" }, { 3, "def"  },
            { 4, "ghi"  }, { 5, "jkl" }, { 6, "mno"  },
            { 7, "pqrs" }, { 8, "tuv" }, { 9, "wxyz" }
        };
        
        vector<string> c;
        for (int i = 0; i < digits.size(); ++ i)
            c.push_back(phone[digits[i] - '0']);
        
        combination(c, 0, tmp);
        
        return result;
    }
    
private:
    void combination(const vector<string>& c, int k, string& s) {
        
        if (k >= c.size()) {
            
            result.push_back(s);
            return;
        }
        
        for (int i = 0; i < c[k].size(); ++ i) {
            
            s.push_back(c[k][i]);
            combination(c, k + 1, s);
            s.pop_back();
        }
    }
    
    vector<string> result;
    string tmp;
};
