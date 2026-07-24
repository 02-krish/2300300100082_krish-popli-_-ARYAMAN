class Solution {
public:
    int n;
    vector<int> memo;

    int getNextIndex(vector<vector<int>>& jobs, int l, int endTime) {
        int r = n - 1;
        int ans = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (jobs[mid][0] >= endTime) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }

    int solve(vector<vector<int>>& jobs, int i) {
        if (i >= n)
            return 0;

        if (memo[i] != -1)
            return memo[i];

        int next = getNextIndex(jobs, i + 1, jobs[i][1]);

        int take = jobs[i][2] + solve(jobs, next);
        int notTake = solve(jobs, i + 1);

        return memo[i] = max(take, notTake);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {

        n = startTime.size();
        memo.assign(n + 1, -1);

        vector<vector<int>> jobs;

        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        return solve(jobs, 0);
    }
};