class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        if (n == 0)
            return false;
        int m = matrix[0].size();
        if (m == 0)
            return false;

        vector<int> firstCol;
        for (int i = 0; i < n; ++ i)
            firstCol.push_back(matrix[i][0]);

        int x = search(firstCol, target);
        if (x == -1)
            return false;

        int y = search(matrix[x], target);
        return matrix[x][y] == target;
    }
private:
    int search(vector<int>& vec, int target) {

        int left = 0, right = vec.size() - 1;
        while (left <= right) {

            int mid = left + (right - left) / 2;
            if (vec[mid] < target)
                left = mid + 1;
            else if (vec[mid] > target)
                right = mid - 1;
            else
                return mid;
        }
        return right;
    }
};
