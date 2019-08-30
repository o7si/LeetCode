class Solution {
public:
    int myAtoi(string str) {
        
        // 丢弃空格
        stringstream stream(str);
        string snum;
        stream >> snum;
        
        // 当第一个字符不是加减符号或数字时无法进行转换
        if (snum[0] != '+' && snum[0] != '-' && !isdigit(snum[0]))
            return 0;
        
        double num = 0;
        for (int i = !isdigit(snum[0]) ? 1 : 0; i < snum.size(); ++ i) {
            
            // 转换途中遇到数字字符之外的其他字符
            if (!isdigit(snum[i]))
                break;
            
            num = num * 10 + snum[i] - '0';
        }
        
        if (snum[0] == '-')
            num = -num;
        
        // 如果上溢出
        if (num > INT_MAX)
            return INT_MAX;
        // 如果下溢出
        if (num < INT_MIN)
            return INT_MIN;
        // 如果未溢出
        return static_cast<int>(num);
    }
};
