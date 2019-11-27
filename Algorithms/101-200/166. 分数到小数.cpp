class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {

        // 分子为零
        if (numerator == 0)
            return to_string(0);

        // 结果是否为负数
        bool negative = numerator < 0 ^ denominator < 0;
        
        // 防止溢出
        long lnumerator = labs(numerator);
        long ldenominator = labs(denominator);

        string istr = to_string(lnumerator / ldenominator);
        long remainder = lnumerator % ldenominator;
        // 无小数部分
        if (remainder == 0)
            return (negative ? "-" : "") + istr;

        // 计算小数部分
        unordered_map<long, int> hash;
        string fstr;
        int index = 0;

        while (remainder != 0 && hash.find(remainder) == hash.end()) {
            
            hash[remainder] = index ++;
            remainder *= 10;
            fstr += remainder / ldenominator + '0';
            remainder %= ldenominator;
        }

        // 无循环节
        if (remainder == 0)
            return (negative ? "-" : "") + istr + "." + fstr;

        // 加括号
        fstr.insert(fstr.begin() + hash[remainder], '(');
        fstr.insert(fstr.end(), ')');

        return (negative ? "-" : "") + istr + "." + fstr;
    }
};
