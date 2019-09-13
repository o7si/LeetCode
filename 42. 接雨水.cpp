class Solution {
public:
    int trap(vector<int>& height) {
        
        int result = 0;
        stack<int> c;
        int i = 0;
        while (i < height.size()) {

            while (!c.empty() && height[i] > height[c.top()]) {

                int bottom = height[c.top()];
                c.pop();
                
                if (c.empty())
                    break;
                
                result += (i - c.top() - 1) * (min(height[i], height[c.top()]) - bottom);
            }
            c.push(i ++);
        }
        return result;
    }
};
