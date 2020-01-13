class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        if (board.empty())
            return;

        this->matrixN = board.size();
        this->matrixM = board[0].size();

        for (int i = 0; i < matrixN; ++ i) {

            for (int j = 0; j < matrixM; ++ j) {

                if ((i == 0 || i == matrixN - 1 || j == 0 || j == matrixM - 1) && board[i][j] == 'O')
                    mark(board, i, j);
            }
        }

        for (int i = 0; i < matrixN; ++ i) {

            for (int j = 0; j < matrixM; ++ j) {

                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == 'M')
                    board[i][j] = 'O';
            }
        }
    }
private:
    void mark(vector<vector<char>>& board, int x, int y) {

        queue<pair<int, int>> c;
        c.push(make_pair(x, y));
        board[x][y] = 'M';

        while (!c.empty()) {

            pair<int, int> cur = c.front();
            c.pop();

            int dx[] = { -1, 0, 1, 0 };
            int dy[] = { 0, 1, 0, -1 };

            for (int k = 0; k < 4; ++ k) {

                int tx = cur.first + dx[k];
                int ty = cur.second + dy[k];

                if (tx < 0 || tx >= matrixN || ty < 0 || ty >= matrixM)
                    continue;

                if (board[tx][ty] != 'O')
                    continue;

                c.push(make_pair(tx, ty));
                board[tx][ty] = 'M';
            }
        }
    }
    int matrixN;
    int matrixM;
};
