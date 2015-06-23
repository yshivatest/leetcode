#include<iostream>
#include<unordered_map>
#include<utility>
using namespace std;
class Solution {
public:
    int calculate(int n) {
        int sum = 0;
        while(n) {
            sum += ((n%10) * (n%10));
            n = n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        if (n <= 0)
            return false;
        unordered_map<int,int> temp;
        int i = 1;
        while(n != 1) {
            n = calculate(n);
            auto x = temp.insert(make_pair(n,i));
            if (!x.second)
                return false;
        }
        return true;
    }
};

int main()
{
	Solution s;
	cout<<s.isHappy(19)<<endl;
}
