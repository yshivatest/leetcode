class Solution {
public:
    bool isvalidpos(vector<int>& qs, int row) {
        for(int i = 0; i < row; i++) {
            if(qs[row] == qs[i] || abs(row-i) == abs(qs[row]-qs[i]))
                return false;
        }
        return true;
    }
    
    void addoutput(vector<int>& qs, vector<vector<string>>& ret) {
        string x="";
        for(int i = 0; i < qs.size(); i++)
            x += ".";
        vector<string> out;
        for(int i = 0; i < qs.size();i++) {
            x[qs[i]] = 'Q';
            out.push_back(x);
            x[qs[i]] = '.';
        }
        ret.push_back(out);
    }
    
    void solveNQueens__(int start, int end, vector<int>& qs, vector<vector<string>>& ret) {
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
            addoutput(qs, ret);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> qs(n, -1);
        vector<vector<string>> ret;
        //rows numbered 0 to n-1
        solveNQueens__(0,n,qs, ret);
        return ret;
    }
};
