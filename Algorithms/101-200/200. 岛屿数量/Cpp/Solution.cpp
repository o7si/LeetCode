class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int count = 0;
        for (int i = 0; i < grid.size(); ++ i) {

            for (int j = 0; j < grid[i].size(); ++ j) {

                if (grid[i][j] == '0')
                    continue;

                mark(grid, i, j);
                ++ count;
            }
        }
        return count;
    }
private:
    void mark(vector<vector<char>>& grid, int x, int y) {

        queue<pair<int, int>> c;
        c.push(make_pair(x, y));
        grid[x][y] = '0';

        while (!c.empty()) {

            pair<int, int> cur = c.front();
            c.pop();

            // → ↓ ← ↑
            int dx[] = { 0, 1, 0, -1 };
            int dy[] = { 1, 0, -1, 0 };
            
            for (int k = 0; k < 4; ++ k) {

                int tx = cur.first + dx[k];
                int ty = cur.second + dy[k];

                if (tx < 0 || tx >= grid.size() || ty < 0 || ty >= grid[tx].size())
                    continue;

                if (grid[tx][ty] == '0')
                    continue;

                c.push(make_pair(tx, ty));
                grid[tx][ty] = '0';
            }
        }
    }
};
