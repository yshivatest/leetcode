#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    void reverseWords(string &s) {
        if (!s.size())
            return;
        int leadspace = 0, trailspace = 0;
        int i;
        for(i = 0; i < s.size() && s[i] == ' '; i++)
            ;
        if (i == s.size()) {
            s = "";
            return;
        }
        s = s.substr(i, s.size()-i);
        for(i = 0; i < s.size() && s[s.size() - i -1] == ' '; i++) {
            ;
        }
        if (i == s.size()) {
            s="";
            return;
        }
        s = s.substr(0, s.size() - i);
        int start = -1, count = 0;
        for (i = 1; i < s.size(); i++) {
            cout<<count<<","<<start<<endl;
            if (s[i] == ' ') {
                if (!count) {
                    count++;
                    start = i;
                } else {
                    count++;
                }
            } else {
                if (count <= 1) {
                    count = 0;
                    start = -1;
                } else {
                    s = s.substr(0, start) + " "+s.substr(i, s.size() - i);
                    count = 0;
                    start = -1;
                    i = start;
                } 
            }
        }

        cout<<s<<endl;
        //reverse string
        for(i = 0; i < s.size()/2; i++) {
            swap(s[i], s[s.size()-1-i]);
        }
        for(i = 0, start = 0; i < s.size();i++) {
            if (s[i]==' ') {
                if (start != i) {
                    //reverse start to i -1
                    for(int j = start; j < (start + i -1)/2; j++)
                        swap(s[j],s[i-1-(j-start)]);
                }
                start = i+1;
            }
        }
    }
};

int main()
{
    string s = "   a   b  c d   e  ";
    Solution x;
    x.reverseWords(s);
    cout<<s<<endl;
}
