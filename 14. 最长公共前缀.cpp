class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
     
        if (strs.empty())
            return "";
        
        string prefix = strs[0];
        
        int curEnd = prefix.size();
        for (int i = 1; i < strs.size(); ++ i) {
            
            curEnd = min(curEnd, static_cast<int>(strs[i].size()));
            for (int j = 0; j < curEnd; ++j) {
                
                if (strs[i][j] != prefix[j]) {
                    curEnd = j;
                    break;
                }   
            }
        }

        return prefix.substr(0, curEnd);
    }
};
