#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class mycompare {
public:
    bool operator()(const int x, const int y) {
        return x <= y;
    }
};

class Solution {
public:
    void construct_maxheap(const vector<int>& nums) {
        priority_queue<int, vector<int>, mycompare> maxheap;
        for (int i = 0; i < nums.size(); i++) {
            maxheap.emplace(nums[i]);
        }
        while(!maxheap.empty()) {
            cout<<maxheap.top()<<",";
            maxheap.pop();
        }
        cout<<endl;
    }
};

int main()
{
    vector<int> temp{9,1,8,2,3,4};
    Solution x;
    x.construct_maxheap(temp);
    return 0;
}
