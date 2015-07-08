#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
/*
Maximum Product Subarray Total Accepted: 32959 Total Submissions: 169903 My Submissions Question Solution 
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (!nums.size())
            return -1;
        if (nums.size() == 1)
            return nums[0];
        
        int ret = INT_MIN, cur = 1, consider_cur = 0, neg1 = INT_MIN, neg2 = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                ret = max({ret, neg1*cur, neg2*cur, 0});
                if (consider_cur)
                    ret = max(ret, cur);
                cur = 1;
                consider_cur = 0;
                neg1 = INT_MIN;
                neg2 = INT_MIN;
            } else if (nums[i] > 0) {
                cur = cur*nums[i];
                consider_cur = 1;
            } else {
                if (neg1 == INT_MIN) {
                    neg1 = nums[i] * cur;
                } else if (neg2 == INT_MIN) {
                    neg2 = nums[i] * cur;
                    neg1 = neg1 * neg2;
                } else {
                    ret = max({ret, neg1*cur, neg2*cur});
                    neg1 = neg1 * cur * nums[i];
                    neg2 = neg2 * cur * nums[i];
                }
                ret = max({ret, neg1, neg2});
                if(consider_cur)
                    ret = max(ret, cur);
                cur = 1;
                consider_cur = 0;
            }
        }
        ret =  max({ret, neg1 * cur, neg2 * cur});
        if (consider_cur)
            ret = max(ret, cur);
        return ret;
    }
};

int main()
{
    vector<int> x{3,-2,-3,3,-1,0,1};
    Solution s;
    cout<<s.maxProduct(x);
}
