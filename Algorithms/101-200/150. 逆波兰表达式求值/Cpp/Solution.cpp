class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> c;
        for (int i = 0; i < tokens.size(); ++ i) {
            
            string tmp = tokens[i];
            if (tmp != "+" && tmp != "-" && tmp != "*" && tmp != "/") {

                c.push(stoi(tmp));
                continue;
            }

            int right = c.top();
            c.pop();
            int left = c.top();
            c.pop();

            if (tmp == "+")
                c.push(left + right);
            else if (tmp == "-")
                c.push(left - right);
            else if (tmp == "*")
                c.push(left * right);
            else if (tmp == "/")
                c.push(left / right);
        }
        return c.top();
    }
};
