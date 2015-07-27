class Solution {
public:
    bool isvalidpos(vector<int>& qs, int row) {
        for(int i = 0; i < row; i++) {
            if(qs[row] == qs[i] || abs(row-i) == abs(qs[row]-qs[i]))
                return false;
        }
        return true;
    }
    
    void solveNQueens__(int start, int end, vector<int>& qs, int& ret) {
        if (start < end) {
            for(int i = 0; i < end; i++) {
                qs[start] = i;
                if (isvalidpos(qs, start)) {
                    solveNQueens__(start+1, end, qs, ret);
                } else {
                    qs[start] = -1;
                }
            }
        } else {
            // push qs to ret
            ret++;
        }
    }

    int totalNQueens(int n) {
        vector<int> qs(n, -1);
        int ret=0;
        //rows numbered 0 to n-1
        solveNQueens__(0,n,qs, ret);
        return ret;
    }
};
