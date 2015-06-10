#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int ar1[128] = {0}, ar2[128]={0};
        for (int i = 0; i < s.size(); i++) {
            if (ar1[s[i]] == 0 && ar2[t[i]] == 0) {
                ar1[s[i]] = t[i];
                ar2[t[i]] = s[i];
            } else if (ar1[s[i]] != t[i] || ar2[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};


int main()
{
    string s{"siva"}, t{"kris"};
    cout<<s<<","<<t<<endl;
    Solution x;
    cout<<x.isIsomorphic(s,t)<<endl;
}
