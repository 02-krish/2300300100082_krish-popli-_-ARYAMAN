class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        if (amount == 0)
            return 0;

        queue<int> q;
        vector<bool> vis(amount + 1, false);

        q.push(amount);
        vis[amount] = true;

        int level = 0;

        while (!q.empty()) {

            int size = q.size();
            level++;

            while (size--) {

                int curr = q.front();
                q.pop();

                for (int coin : coins) {

                    int next = curr - coin;

                    if (next == 0)
                        return level;

                    if (next > 0 && !vis[next]) {
                        vis[next] = true;
                        q.push(next);
                    }
                }
            }
        }

        return -1;
    }
};