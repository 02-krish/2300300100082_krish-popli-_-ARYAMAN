class Solution {
public:
    int jump(vector<int>& arr) {
        int n = arr.size();
    int l = 0, r = 0;
    int jumps = 0;

    while (r < n - 1) {
        int f = 0;

        for (int i = l; i <= r; i++) {
            f = max(f, i + arr[i]);
        }

        l = r + 1;
        r = f;  // 🔥 IMPORTANT FIX
        jumps++;
    }

    return jumps;
    }
};