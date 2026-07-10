class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        int i, j;
        int sr = 0 , sc = 0, er = m - 1, ec = n - 1;
        while (sr <= er && sc <= ec) {
            for (j = sc; j <= ec; j++) {
                // toppppp
                res.push_back(matrix[sr][j]);
            }
            for (i = sr + 1; i <= er; i++) {
                res.push_back(matrix[i][ec]); // right
            }
            for (j = ec-1; j >= sc; j--) {
                if (sr == er)
                    break;
                res.push_back(matrix[er][j]);
            }

            for (i = er - 1; i >= sr + 1; i--) {
                if (sc == ec)
                    break;
                res.push_back(matrix[i][sc]);
            }
            sr++;sc++;er--;ec--;
        }

        return res;
    }
};