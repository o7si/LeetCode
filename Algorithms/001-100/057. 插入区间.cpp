class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
 
        if (intervals.empty()) {

            vector<vector<int>> result;
            result.push_back(newInterval);
            return result;
        }

        int minValue = intervals[0][0], maxValue = intervals[intervals.size() - 1][1];

        if (newInterval[0] > maxValue) {
            
            // 插入到尾部
            vector<vector<int>> result;
            for (int i = 0; i < intervals.size(); ++ i)
                result.push_back(intervals[i]);
            result.push_back(newInterval);
            return result;
        }
        if (newInterval[1] < minValue){

            // 插入到首部
            vector<vector<int>> result;
            result.push_back(newInterval);
            for (int i = 0; i < intervals.size(); ++ i)
                result.push_back(intervals[i]);
            return result;
        }

        int leftFoot = -1, rightFoot = -1;
        for (int i = 0; i < intervals.size(); ++ i) {

            if (intervals[i][0] <= newInterval[0] && newInterval[0] <= intervals[i][1])
                leftFoot = i * 2;
            if (i + 1 < intervals.size() && intervals[i][1] < newInterval[0] && newInterval[0] < intervals[i + 1][0])
                leftFoot = i * 2 + 1;

            if (intervals[i][0] <= newInterval[1] && newInterval[1] <= intervals[i][1])
                rightFoot = i * 2;
            if (i + 1 < intervals.size() && intervals[i][1] < newInterval[1] && newInterval[1] < intervals[i + 1][0])
                rightFoot = i * 2 + 1;
        }

        int leftValue = (leftFoot == -1) || (leftFoot & 1) ? newInterval[0] : intervals[leftFoot / 2][0];
        int rightValue = (rightFoot == -1) || (rightFoot & 1) ? newInterval[1] : intervals[rightFoot / 2][1];
        
        vector<vector<int>> result;
        for (int i = 0; i < intervals.size(); ++ i)
            if (intervals[i][1] < leftValue)
                result.push_back(intervals[i]);
        result.push_back({ leftValue, rightValue });
        for (int i = 0; i < intervals.size(); ++ i)
            if (intervals[i][0] > rightValue)
                result.push_back(intervals[i]);
        return result;
    }
};
