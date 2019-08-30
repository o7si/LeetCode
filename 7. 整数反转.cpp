class Solution {
public:
    int reverse(int x) {
        
        string snum = to_string(x);
        std::reverse(snum.begin() + (x < 0 ? 1 : 0), snum.end());
        
        long rnum = atol(snum.data());
        // 判断反转后整数是否溢出
        if (rnum < INT_MIN || rnum > INT_MAX)
            return 0;
        
        return rnum;
    }
};
