class Solution {
public:
    string intToRoman(int num) {
        
        vector<int> values = { 
            1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 
        };
        vector<string> romans = { 
            "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"
        };
        
        int index = values.size() - 1;
        string roman;
        while (num) {
            
            if (num < values[index]) {
                
                -- index;
                continue;
            }
            
            num -= values[index];
            roman += romans[index];
        }
        
        return roman;
    }
};
