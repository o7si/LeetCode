class Solution {
public:
    int mySqrt(int x) {
        
        long left = 0, right = x;
        while (left <= right) {
            
            long mid = left + (right - left) / 2;
            long square = mid * mid;
            
            if (square == x)
                return mid;
            
            if (square < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left - 1;
    }
};
