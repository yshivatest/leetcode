#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    static bool mycompare(int x, int y) {
        ostringstream out1, out2;
        out1<<x<<y;
        out2<<y<<x;
        string s1 = out1.str(), s2 = out2.str();
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i])
                return (s1[i] - '0') <= (s2[i] - '0');
        }
        return true;
    }

    string largestNumber(vector<int>& nums) {
        if (!nums.size())
            return "";
        //if (nums.size() > 1)
            sort(nums.begin(), nums.end(), mycompare);
        ostringstream out;
        for(int i = nums.size()-1; i >= 0; i--) {
            out<<nums[i];
        }
        cout<<out.str().size()<<endl;
        return out.str();
    }
};

int main()
{
	vector<int> x{302};
	Solution s;
	cout<<s.largestNumber(x)<<endl;
}
