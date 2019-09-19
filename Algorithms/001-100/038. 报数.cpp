class Solution {
public:
    string countAndSay(int n) {
     
        string num = "1";
        while (-- n) {
            
            char ch = num[0];
            string tmp;
            
            num += '#';
            for (int i = 0, count = 0; i < num.size(); ++ i) {
                
                if (num[i] == ch)
                    ++ count;
                else {
                    
                    tmp += to_string(count) + ch;
                    
                    ch = num[i];
                    count = 1;
                }
            }
            num = tmp;
        }
        return num;
    }
};
