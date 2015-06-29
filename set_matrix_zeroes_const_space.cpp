/*
Set Matrix Zeroes Total Accepted: 38744 Total Submissions: 123195 My Submissions Question Solution 
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
        int row = -1, col = -1;
        for(int r = 0; r < matrix.size(); r++) {
            for(int c = 0; c < matrix[r].size(); c++) {
                if (matrix[r][c] == 0) {
                    row = r;
                    col = c;
                    goto out;
                }
            }
        }
        if (row == -1)
            return;
        out:
        for(int r = 0; r < matrix.size(); r++) {
            for(int c = 0; c < matrix[r].size(); c++) {
                if (matrix[r][c] == 0) {
                    matrix[r][col] = 0; 
                    matrix[row][c] = 0;
                }
            }
        }
        //Now matrix[row] has all the columns that need to be set to zero
        //matrix[col] has all the rows that need to be set to zero
        for(int c = 0; c < matrix[row].size(); c++) {
            if (matrix[row][c] == 0 && c != col) {
                //set col c to zero
                for(int r = 0; r < matrix.size(); r++)
                    matrix[r][c] = 0;
            }
        }
        
        for(int r = 0; r < matrix.size(); r++) {
            if (matrix[r][col] == 0 && r != row) {
                //set row r to zero
                for (int c = 0; c < matrix[0].size(); c++)
                    matrix[r][c] = 0;
            }
        }
        //set row and col to zero
        for(int c = 0; c < matrix[row].size(); c++) {
            matrix[row][c] = 0;
        }
        
        for(int r = 0; r < matrix.size(); r++) {
            matrix[r][col] = 0;
        }
        
    }
};
