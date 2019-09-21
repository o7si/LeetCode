class Solution {
public:
    int climbStairs(int n) {
        
        static map<int, int> save = {
            { 0, 1 }, 
            { 1, 1 } 
        };

        if (save.find(n) != save.end())
            return save[n];
        
        return save[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};
