class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        string ans = "";
        int jump = 2 * (numRows - 1);

        for (int i = 0; i < numRows; i++) {

            for (int j = i; j < s.size(); j += jump) {

                ans += s[j];

                int diag = j + jump - 2 * i;

                if (i != 0 && i != numRows - 1 &&
                    diag < s.size()) {
                    ans += s[diag];
                }
            }
        }

        return ans;
    }
};