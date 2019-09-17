class Solution {
public:
    string longestPalindrome(string s) {
        
        int left = 0, right = 0;
        
        // dp[i][j] 表示字符串 s[i, j] 是否为回文串 
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        
        for (int j = 0; j < s.size(); ++ j) {
            
            for (int i = 0; i <= j; ++ i) {
                
                if (j - i == 0) {
                    // 区间 [i, j] 仅有一个字符，肯定是回文串
                    dp[i][j] = true;
                } else if (j - i == 1) {
                    // 区间 [i, j] 有两个字符，当两个字符相等时为回文串
                    dp[i][j] = s[i] == s[j];
                } else {
                    // 包含两个以上的字符
                    // 区间 [i, j] 是回文串的条件：子区间 [i + 1, j - 1] 是回文串而且 s[i] 等于 s[j]
                    dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                }
                
                // 如果找到了更长的回文串
                if (dp[i][j] && j - i > right - left) {
                    
                    left = i;
                    right = j;
                }
            }
        }

        return s.substr(left, right - left + 1);
    }
};
