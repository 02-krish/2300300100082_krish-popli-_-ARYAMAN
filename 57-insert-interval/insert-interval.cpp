class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
         vector<vector<int>> res;
        int i = 0, n = intervals.size();

        // 1️⃣ Left side (no overlap)
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        // 2️⃣ Overlapping intervals (merge)
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        // 3️⃣ Add merged interval
        res.push_back(newInterval);

        // 4️⃣ Right side
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};