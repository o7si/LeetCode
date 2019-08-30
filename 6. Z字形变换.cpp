class Solution {
public:
    string convert(string s, int numRows) {
        
        vector<string> ztmp(numRows);
        
        int k = 0;
        while (k < s.size()) {
            
            // 向下
            for (int i = 0; i < numRows && k < s.size(); ++ i)
                ztmp[i].push_back(s[k ++]);
            // 向上
            for (int i = numRows - 1 - 1; i > 0 && k < s.size(); -- i)
                ztmp[i].push_back(s[k ++]);
        }
        
        string zres;
        for (int i = 0; i < numRows; ++ i)
            zres.append(ztmp[i]);
        return zres;
    }
};
