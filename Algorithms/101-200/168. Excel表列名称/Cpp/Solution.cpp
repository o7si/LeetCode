class Solution {
public:
    string convertToTitle(int n) { 
        
        stack<int> c;
        while (n > 0) {
            
            -- n;
            c.push(n % 26);
            n /= 26;
        }

        string result;
        while (!c.empty()) {
            
            result += 'A' + c.top();
            c.pop();
        }
        return result;
    }
};
