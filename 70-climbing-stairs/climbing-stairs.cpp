
class Solution {
public:
    unordered_map<int,int> dp;

    int solve(int i, int n) {
        if(i == n) return 1;
        if(i > n) return 0;

        if(dp.find(i) != dp.end())
            return dp[i];

        return dp[i] = solve(i+1, n) + solve(i+2, n);
    }

    int climbStairs(int n) {
        return solve(0, n);
    }
};

