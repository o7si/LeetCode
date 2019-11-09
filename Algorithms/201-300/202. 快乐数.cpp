class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set<int> hashset;
        while (n != 1) {

            string snum = to_string(n);
            int tmp = 0;
            for (const char ch : snum) 
                tmp += (ch - '0') * (ch - '0');
            
            if (hashset.find(tmp) != hashset.end())
                return false;
            hashset.insert(n = tmp);
        }
        return true;
    }
};
