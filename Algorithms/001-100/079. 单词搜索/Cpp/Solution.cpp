class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        this->board = board;
        this->boardN = board.size();
        this->boardM = board[0].size();
        this->vis = vector<vector<bool>>(boardN, vector<bool>(boardM, false));
        this->word = word;

        for (int i = 0; i < boardN; ++ i) {

            for (int j = 0; j < boardM; ++ j) {

                if (search(i, j, 0))
                    return true;
            }
        }
        return false;
    }
private:
    bool search(int x, int y, int pos) {

        if (pos >= word.size())
            return true;
        
        if (x < 0 || x >= boardN || y < 0 || y >= boardM)
            return false;

        if (vis[x][y])
            return false;

        if (board[x][y] != word[pos])
            return false;

        static int dx[] = { 0, 1, 0, -1 };
        static int dy[] = { 1, 0, -1, 0 };

        bool result = false;
        vis[x][y] = true;
        for (int k = 0; k < 4 && !result; ++ k) 
            result = search(x + dx[k], y + dy[k], pos + 1);
        vis[x][y] = false;
        return result;
    }
    vector<vector<char>> board;
    vector<vector<bool>> vis;
    int boardN, boardM;
    string word;
};
