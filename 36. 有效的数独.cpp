class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        const int LineN   = 9;
        const int ColumnN = 9;
        const int BlockN  = 9;
        
        vector<map<int, bool>> line(LineN);
        vector<map<int, bool>> column(ColumnN);
        vector<map<int, bool>> block(BlockN);
        
        for (int i = 0; i < LineN; ++ i) {
            
            for (int j = 0; j < ColumnN; ++ j) {
                
                if (board[i][j] == '.')
                    continue;
                
                int num = board[i][j] - '0';
                if (line[i][num] || column[j][num] || block[i / 3 * 3 + j / 3][num])
                    return false;
                
                line[i][num] = true;
                column[j][num] = true;
                block[i / 3 * 3 + j / 3][num] = true;
            }
        }
        
        return true;
    }
};
