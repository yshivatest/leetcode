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
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<PosVal> temp;
        for (int i = 0; i < nums.size();i++) {
            PosVal x = {i,nums[i]};
            temp.push_back(x);
        }
        sort(temp.begin(), temp.end(), posval_compare);
        int i = temp.size() - 1;
        int j = 0; vector<int> ret;
        while(j <= i) {
            int sum = temp[i].val + temp[j].val;
            if (sum == target) {
                if (temp[i].pos < temp[j].pos) {
                    ret.push_back(temp[i].pos+1);
                    ret.push_back(temp[j].pos+1);
                } else {
                    ret.push_back(temp[j].pos+1);
                    ret.push_back(temp[i].pos+1);
                }
                return ret;
            } else if (sum < target) {
                j++;
            } else {
                i--;
            }
        }
        return ret;
    }
};
int main() {
    vector<int> x {-3,4,3,90};
    Solution s;
    vector<int> y = s.twoSum(x,0);
    for (auto& t: y)
        cout<<t<<",";
    cout<<endl;
}
