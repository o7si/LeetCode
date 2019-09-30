class Solution {
public:
    string reverseWords(string s) {
        
        stringstream stream(s);
        stack<string> c;
        string tmp;
        while (stream >> tmp)
            c.push(tmp);
        
        if (c.empty())
            return string();

        string result;
        while (!c.empty()) {

            result += ' ' + c.top();
            c.pop();
        }
        return result.substr(1);
    }
};
