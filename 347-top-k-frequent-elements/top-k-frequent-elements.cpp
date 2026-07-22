class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        // Frequency count
        for (int x : nums)
            mp[x]++;

        // Min Heap -> {frequency, element}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        for (pair<int, int> i : mp) {

            int element = i.first;
            int freq = i.second;

            pair<int, int> curr = {freq, element};

            if (pq.size() < k) {
                pq.push(curr);
                continue;
            }

            if (curr.first > pq.top().first) {
                pq.pop();
                pq.push(curr);
            }
        }

        vector<int> res;

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};