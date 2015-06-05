#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    static bool mycompare(int x, int y)
    {
        return x >= y;
    }
    void construct_minheap(vector<int>& nums)
    {
        priority_queue<int, vector<int>, less<int>> x;
        x.emplace(1);
        x.emplace(2);
        x.emplace(3);
        while(!x.empty()) {
            cout<<x.top()<<",";
            x.pop();
        }
        cout<<endl;
    }
};
int main()
{
    Solution s;
    vector<int> x;
    s.construct_minheap(x);
}
