class Solution {
public:
    string multiply(string snum1, string snum2) {
        
        vector<int> num1(snum1.size());
        for (int i = snum1.size() - 1, j = 0; i >= 0; -- i)
            num1[j ++] = snum1[i] - '0';
        
        vector<int> num2(snum2.size());
        for (int i = snum2.size() - 1, j = 0; i >= 0; -- i)
            num2[j ++] = snum2[i] - '0';
    
        vector<int> multi(snum1.size() + snum2.size());
        for (int i = 0; i < num1.size(); ++ i) {
            for (int j = 0; j < num2.size(); ++ j) {
                
                multi[i + j] += num1[i] * num2[j];
                if (multi[i + j] >= 10) {
                    
                    multi[i + j + 1] += multi[i + j] / 10;
                    multi[i + j] %= 10;
                }
            }
        }
        
        int pos = multi.size() - 1;
        while (pos > 0 && multi[pos] == 0)
            -- pos;
        
        string result;
        while (pos >= 0) 
            result += multi[pos --] + '0';
        
        return result;
    }
};
