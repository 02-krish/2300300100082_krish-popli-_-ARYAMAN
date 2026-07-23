class Solution {
public:
    int minimumSum(int n, int k) {
        set<int> st;
        int sum = 0;
        int size = 0;
        int i = 1;
        while (1) {
            if (size == n) {
                return sum;
                break;
            }
            int temp = k - i;
            if (st.find(temp) != st.end()) {
                i++;
            } else {
                sum += i; st.insert(i);
                i++;
                size++;
               
            }
        }
        return 1;
    }
};