#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() <= 1)
            return false;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1])
                return true;
        }
    }
};

int main()
{
    vector<int> x {1,2,1};
    Solution s;
    cout<<s.containsDuplicate(x)<<endl;
}
