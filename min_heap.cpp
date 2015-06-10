#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class mycompare {
public:
    bool operator()(const int x, const int y) {
        return x >= y;
    }
};
class Solution {
public:
    void construct_minheap(vector<int>& nums)
    {
        //priority_queue<int, vector<int>, greater<int>> x;
        priority_queue<int, vector<int>, mycompare> x;
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
