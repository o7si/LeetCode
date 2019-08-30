class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // 维护区间：[start, cur)
        size_t start = 0, cur = 0;
        size_t len = 0;
        
        set<char> cset;
        while (cur < s.size()) {
            
            if (cset.find(s[cur]) == cset.end()) {
                
                // 集合中无该字符则加入集合
                cset.insert(s[cur ++]);
            } else {
                
                // 集合中有该元素说明[start, cur)出现重复字符
                cset.erase(s[start ++]);
            }
            
            len = max(len, cur - start);
        }
        
        return len;
    }
};
