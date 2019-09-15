class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
        this->board = vector<string>(n, string(n, '.'));
        this->size = n;

        search();
        return result;
    }
private:
    void search(int line = 0, int col = 0, int toUp = 0, int toDown = 0) {

        if (line >= size) {
            
            result.push_back(board);
            return;
        }

        for (int i = 0; i < size; ++ i) {

            if ((col >> i & 1) || (toUp >> (line + i) & 1) || (toDown >> (line - i + size - 1) & 1))
                continue;
            
            board[line][i] = 'Q';
            search(line + 1, col | 1 << i, toUp | 1 << (line + i), toDown | 1 << (line - i + size - 1));
            board[line][i] = '.';
        }
    }

    vector<vector<string>> result;
    vector<string> board;
    int size;
};
