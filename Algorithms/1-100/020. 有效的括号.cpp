class Solution {
public:
    bool isValid(string s) {
        
        stack<char> c;
        for (int i = 0; i < s.size(); ++ i) {
            
            if (c.empty() || !paired(c.top(), s[i])) {
                // 当不匹配时执行的操作
                c.push(s[i]);
            } else {
                // 当匹配时执行的操作
                c.pop();
            }
        }
        
        return c.empty();
    }
private:
    bool paired(char top, char cur) {
        
        return (top == '(' && cur == ')') || 
               (top == '{' && cur == '}') || 
               (top == '[' && cur == ']');
    }
};
