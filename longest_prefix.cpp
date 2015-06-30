class Solution {
public:
    bool whatever(vector<string>& strs, char c, int x) {
        for(int i = 1; i < strs.size(); i++) {
            if(c != strs[i][x])
                return false;
        }
        return true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        if (strs.size() == 1)
            return strs[0];
        int i;
        for(i = 0; i < strs[0].size(); i++) {
            if (!whatever(strs, strs[0][i], i)) 
                break;
        }
        return strs[0].substr(0,i);
    }
};
