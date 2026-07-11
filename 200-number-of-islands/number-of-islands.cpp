class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    bool valid(int i, int j, int n, int m)
    {
        if (i < 0 || i >= n || j < 0 || j >= m)
        {
            return false;
        }
        return true;
    }

    void dfs(vector<vector<char>>& grid, int n, int m,
             int i, int j, vector<vector<bool>>& vis)
    {
        vis[i][j] = true;

        for (int k = 0; k < 4; k++)
        {
            int row = i + x[k];
            int col = j + y[k];

            if (valid(row, col, n, m) &&
                grid[row][col] == '1' &&
                vis[row][col] == false)
            {
                dfs(grid, n, m, row, col, vis);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n);

        for (int i = 0; i < n; i++)
        {
            vis[i] = vector<bool>(m, false);
        }

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && vis[i][j] == false)
                {
                    cnt++;
                    dfs(grid, n, m, i, j, vis);
                }
            }
        }

        return cnt;
    }
};
