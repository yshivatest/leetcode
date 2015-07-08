#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int fibonacci(int n) {
        int p1 = 0, p2 = 1;
        for(int i = 2; i <=n; i++) {
            p1 = p1 + p2;
            swap(p1, p2);
        }
        return p2;
    }
};
int main()
{
    Solution s;
    for(int i = 1; i < 10; i++)
        cout<<s.fibonacci(i)<<" ";
    cout<<endl;
}
