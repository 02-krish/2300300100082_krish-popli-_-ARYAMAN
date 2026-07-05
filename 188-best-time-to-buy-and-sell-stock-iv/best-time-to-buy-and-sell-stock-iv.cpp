class Solution {
public:

    int fun(vector<int>& prices, int n, int i, int k, vector<vector<int>>& dp)
    {
        if(i == n || k == 0)
            return 0;

        if(dp[i][k] != -1)
            return dp[i][k];

        if(k%2==0)
        {
            int buy = fun(prices, n, i+1, k-1, dp) - prices[i];
            int skip = fun(prices, n, i+1, k, dp);

            return dp[i][k] = max(buy, skip);
        }
        else
        {
            int sell = fun(prices, n, i+1, k-1, dp) + prices[i];
            int skip = fun(prices, n, i+1, k, dp);

            return dp[i][k] = max(sell, skip);
        }
    }

    int maxProfit( int k,vector<int>& prices)
    {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(k*2+1  , -1));

        return fun(prices, n, 0, k*2, dp);
    }
};