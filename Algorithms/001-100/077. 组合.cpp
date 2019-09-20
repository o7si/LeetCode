class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        
        search(n, k);
        return result;
    }
private:
    void search(int n, int k, int pos = 0) {

        if (path.size() >= k) {

            result.push_back(path);
            return;
        }

        for (int i = pos + 1; i <= n; ++ i) {

            path.push_back(i);
            search(n, k, i);
            path.pop_back();
        }
    }
    vector<vector<int>> result;
    vector<int> path;
};
