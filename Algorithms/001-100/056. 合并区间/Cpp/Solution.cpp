class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        vector<bool> has(intervals.size(), true);

        int cur = 0;
        while (cur < intervals.size()) {

            int next = cur + 1;
            while (next < intervals.size() && !has[next])
                ++ next;

            if (next >= intervals.size())
                break;

            if (intervals[cur][1] >= intervals[next][0]) {

                intervals[cur][1] = max(intervals[cur][1], intervals[next][1]);
                has[next] = false;
            } else {
                
                ++ cur;
                while (cur < intervals.size() && !has[cur])
                    ++ cur;
            }
        }

        vector<vector<int>> result;
        for (int i = 0; i < intervals.size(); ++ i)
            if (has[i])
                result.push_back(intervals[i]);

        return result;
    }
};
