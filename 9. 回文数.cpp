class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0)
            return false;
        
        long rnum = 0, num = x;
        while (x) {
            
            rnum = rnum * 10 + x % 10;
            x /= 10;
        }
        
        return rnum == num;
    }
};
