#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0)
            return false;
        if (nums.size() <= 1)
            return false;
        int j = 0;
        auto i = nums.begin();
        for(; j < nums.size() - k; j++, i++) {
            auto x = find(i+1, i+1+k, *i);
            if (x != i+1+k)
                return true;
        }
        if (j == nums.size() - 1)
            return false;
        for(;i != nums.end() - 1; i++) {
            auto x = find(i+1, nums.end(), *i);
            if (x != nums.end())
                return true;
        }
        return false;
    }
};

int main()
{
    Solution x;
    vector<int> y = {1,2,3,3};
    cout<<x.containsNearbyDuplicate(y, 2)<<endl;
}
