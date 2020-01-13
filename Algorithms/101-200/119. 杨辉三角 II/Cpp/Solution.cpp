iclass Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> result(rowIndex + 1, 1);

        for (int row = 2; row <= rowIndex; ++ row)
            for (int col = row - 1; col > 0; -- col)
                result[col] += result[col - 1];

        return result;
    }
};
