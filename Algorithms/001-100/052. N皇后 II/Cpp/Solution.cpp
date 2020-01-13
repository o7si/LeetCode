class Solution {
public:
    int totalNQueens(int n) {
        
        this->size = n;
        this->count = 0;

        search();
        return count;
    }
private:
    void search(int line = 0, int column = 0, int toUp = 0, int toDown = 0) {

        if (line >= size) {

            ++ count;
            return;
        }

        for (int i = 0; i < size; ++ i) {

            if ((column >> i & 1) || (toUp >> (line + i) & 1) || (toDown >> (line - i + size - 1) & 1))
                continue;
            search(line + 1, column | 1 << i, toUp | 1 << (line + i), toDown | 1 << (line - i + size - 1));
        }
    }

    int size;
    int count;
};
