#include<string>
#include<vector>
#include<iostream>
using namespace std;
/*
Regular Expression Matching  
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/
class Solution {
public:

    bool isMatch(string s, string p) {

        if (s.size() == 0) {
            for(int i = 0; i < p.size();i++) {
                if (p[i] != '*')
                    return false;
            }
        }
        
        if (p.size() == 0) {
            return s.size()?false:true;
        }
        

        // 0 - false match
        // 1 - matches
        //-1 not yet checked
        vector<vector<int>> x(s.size()+1, vector<int>(p.size()+1, -1)); 
        x[0][0] = 1;
        for(int i = 1; i <= s.size();i++) {
            x[i][0] = 0;
        }
        for(int i = 1; i <= p.size();i++) {
            x[0][i] = 0;
            
            if (x[0][i-1] ==1 && p[i-1] == '*')
                x[0][i] = 1;
        }
        
        for(int i = 1; i <= s.size(); i++) {
            for(int j = 1; j <= p.size(); j++) {
                x[i][j] = 0;
                if (x[i-1][j-1] == 1 && s[i-1] == p[j-1]) {
                    x[i][j] = 1;
                } else if (p[j-1] == '*') {
                    x[i][j] = x[i-1][j] | x[i][j-1];
                } else if (p[j-1] == '.') {
                    x[i][j] = x[i-1][j-1];
                }
            }
        }
        for(int i = 0; i <= s.size(); i++) {
            for(int j = 0; j <=p.size(); j++)
                cout<<x[i][j]<<",";
            cout<<endl;
        }
        cout<<endl;
        return x[s.size()][p.size()];
        
    }
};

int main()
{
    Solution s;
    cout<<s.isMatch("aab", "c*a*b")<<endl;
}
