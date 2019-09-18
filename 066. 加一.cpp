class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        reverse(digits.begin(), digits.end());
        ++*digits.begin();
        for (int i = 0; i < digits.size(); ++ i) {
            
            if (digits[i] >= 10) {
                
                if (i + 1 >= digits.size())
                    digits.push_back(0);
                
                ++ digits[i + 1];
                digits[i] %= 10;
            }
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
