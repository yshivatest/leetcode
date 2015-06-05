#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    struct PosVal {
    public:
        int pos;
        int val;
    };
    static bool posval_compare(PosVal x, PosVal y) {
        return x.val <= y.val;
    }
    vector<int> twoSquareSum(vector<int>& nums) {
        vector<PosVal> temp;
        for (int i = 0; i < nums.size(); i++) {
            PosVal x{i, nums[i] * nums[i]};
            temp.push_back(x);
        }
        sort(temp.begin(), temp.end(), posval_compare);
        int j = temp.size() - 1;
        int i = 0;
        vector<int> ret;
        for (int k = 2; k < temp.size(); k++) {
            j = k - 1;
            i = 0;
            int target = temp[k].val;
            while(i <= j) {
                int sum = temp[i].val + temp[j].val;
                if (sum == target) {
                    ret.push_back(min(temp[i].pos+1, temp[j].pos+1));
                    ret.push_back(max(temp[i].pos+1, temp[j].pos+1));
                    return ret;
                } else if (sum < target) {
                    i++;
                } else {
                    j--;
                }
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> x{4,3,15};
    Solution s;
    vector<int> t = s.twoSquareSum(x);
    for (auto& i: t) {
        cout<<i<<",";
    }
}
