/*
Set Matrix Zeroes Total Accepted: 38742 Total Submissions: 123188 My Submissions Question Solution 
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (!matrix.size() || !matrix[0].size())
            return;
        vector<int> rows(matrix.size(), 1), cols(matrix[0].size(), 1);
        for(int r = 0; r < matrix.size(); r++) {
            for(int c = 0; c < matrix[r].size(); c++) {
                if (matrix[r][c] == 0) {
                    rows[r] = 0;
                    cols[c] = 0;
                }
            }
        }
        for (int r = 0; r < rows.size(); r++) {
            if (rows[r] != 0)
                continue;
            for(int c = 0; c < matrix[r].size(); c++) {
                matrix[r][c] = 0;
            }
        }
        
        for(int c = 0; c < cols.size(); c++) {
            if (cols[c] != 0)
                continue;
            for(int r = 0; r < rows.size(); r++) 
                matrix[r][c] = 0;
        }
        
    }
};
