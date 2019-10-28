class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        if (points.empty())
            return 0;
     
        sort(points.begin(), points.end());

        for (int i = 0; i < points.size(); ++ i)
            cout << points[i][0] << " " << points[i][1] << endl;

        int count = 1;
        int end = points[0][1];
        for (int i = 1; i < points.size(); ++ i) {

            if (points[i][0] <= end) {

                end = min(end, points[i][1]);
            } else {

                end = points[i][1];
                ++ count;
            }
        }
        return count;
    }
};
