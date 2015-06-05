#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    struct x{
      int val;
      int pos;
      x(int v, int p) : val{v}, pos{p} {}
    };
    static bool mycompare(x a, x b) {
        if (a.val <= b.val)
            return true;
        return false;
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() <= 1)
            return false;
        if (k <= 0)
            return false;
        vector<x> pnums;
        for (int i = 0; i < nums.size(); i++) {
            x temp{nums[i],i};
            pnums.push_back(temp);
        }
        sort(pnums.begin(), pnums.end(), mycompare);
        for (int i = 1; i < pnums.size(); i++) {
            if (pnums[i].val == pnums[i-1].val && abs(pnums[i].pos - pnums[i-1].pos) <= k) {
                cout<<pnums[i].val<<","<<pnums[i].pos<<","<<pnums[i-1].pos<<endl;
                return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<int> y{1,2,1};
    Solution s;
    cout<<s.containsNearbyDuplicate(y, 1)<<endl;
}
