class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowcnt = matrix.size(), colcnt = matrix[0].size();
        vector<bool> rows(rowcnt, false);
        vector<bool> cols(colcnt, false);
        for (int i = 0; i < rowcnt; ++i) {
            for (int j = 0; j < colcnt; ++j) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }    

        for (int i = 0; i < rowcnt; ++i) {
            for (int j = 0; j < colcnt; ++j) {
                if (rows[i] || cols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }          
    }
};
