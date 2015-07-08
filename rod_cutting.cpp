#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int rod_cut(int n, vector<int>& p) {
        vector<int> vals{n+1};
        for(auto x:vals)
            x = INT_MIN;
        vals[0] = 0;
        for(int i = 1; i <= n; i++) {
            int q = INT_MIN;
            for(int j = 1; j <= i; j++) {
                q = max(q, p[j] + vals[i-j]);
            }
            vals[i] = q;
        }
        return vals[n];
    }
};

int main()
{
    vector<int> p;
    p.push_back(0);
    int n;
    cout<<"Enter the number of vals\n";
    cin>>n;
    cout<<"Enter the vals\n";
    for(int i = 1; i <= n; i++) {
        int x;
        cin>>x;
        p.push_back(x);
    }
    Solution s;
    cout<<s.rod_cut(n, p);
}
