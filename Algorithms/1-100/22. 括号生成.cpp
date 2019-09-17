class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        generate(0, 0, n);
        return result;
    }
    
private:
    void generate(int left, int right, int n) {
        
        if (left >= n && right >= n) {
            
            result.push_back(tmp);
            return;
        }
        
        // 放置右括号
        if (left > right) {
            
            tmp.push_back(')');
            generate(left, right + 1, n);
            tmp.pop_back();
        }
        
        // 放置左括号
        if (left < n) {
            
            tmp.push_back('(');
            generate(left + 1, right, n);
            tmp.pop_back();
        }   
    }
    
    vector<string> result;
    string tmp;
};
