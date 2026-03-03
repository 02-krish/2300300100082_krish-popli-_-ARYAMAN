class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
        int sum = 0;

        // first k elements ka sum
        for(int i = 0; i < k; i++) {
            sum += arr[i];
        }

        int maxsum = sum;
        int r = n - 1;

        // sliding window
        for(int i = k - 1; i >= 0; i--) {
            sum -= arr[i];
            sum += arr[r];
            r--;
            maxsum = max(maxsum, sum);
        }

        return maxsum;
    }
};