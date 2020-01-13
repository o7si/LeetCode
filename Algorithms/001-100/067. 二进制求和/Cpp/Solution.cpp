class Solution {
public:
    string addBinary(string a, string b) {
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string result;
        int pos = 0, carry = 0;
        while (pos < a.size() || pos < b.size() || carry) {
            
            int num1 = pos < a.size() ? a[pos] - '0' : 0;
            int num2 = pos < b.size() ? b[pos] - '0' : 0;
            int sum = num1 + num2 + carry;

            result += sum % 2 + '0';
            carry = sum / 2;
            ++ pos;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
