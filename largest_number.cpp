#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
class Solution {
public:

    //return true if x >= y
    static int numc;
    static bool mycompare(pair<int,int> x, pair<int,int> y) {
        numc++;
        cout<<"comparing "<<x.first<<","<<y.first<<","<<numc<<endl;
        if (!y.first)
            return false;
        if (!x.first)
            return true;
        int xnum = x.second - 1;
        int ynum = y.second - 1;
        int divisor1 = 1, divisor2 = 1;
        while(xnum) {
            divisor1 *= 10;
            xnum--;
        }
        
        while(ynum) {
            divisor2 *= 10;
            ynum--;
        }
        
        int num1 = x.first;
        int num2 = y.first;
        
        int num1first = num1/divisor1;
        int num2first = num2/divisor2;
        
        //compare the numbers
        while(divisor1 && divisor2) {
            if (num1/divisor1 == num2/divisor2) {
                num1 %= divisor1;
                num2 %= divisor2;
                divisor1 /= 10;
                divisor2 /= 10;                
            } else {
                return num1/divisor1 >= num2/divisor2;
            }
        }
        
        if (!divisor1 && !divisor2)
            return true;
        if (!divisor1) {
            num1 = num1first;
            num2 = num2/divisor2;
        }
        if (!divisor2) {
            num2 = num2first;
            num1 = num1/divisor1;
        }
        
        return num1 >= num2;

    }
    
    int numDigits(int x) {
        if (x == 0) {
            return 1;
        } else {
            int count = 0;
            while(x) {
                x = x/10;
                count++;
            }
            return count;
        }
    }
    
    string largestNumber(vector<int>& nums) {
        if (!nums.size())
            return "";
        vector<pair<int,int>> temp;
        for(int i = 0; i < nums.size(); i++) {
            temp.push_back(make_pair(nums[i], numDigits(nums[i])));
        }
        cout<<"before sort\n";
        sort(temp.begin(), temp.end(), mycompare);
        cout<<"after sort\n";
        ostringstream out;
        for(int i = 0; i < temp.size(); i++) {
            out<<temp[i].first;
        }
        return out.str();
    }
};

int Solution::numc = 0;
int main()
{
	vector<int> x={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};	
        //vector<int> x ={12,121};
        //x.resize(17);
	Solution s;
	cout<<s.largestNumber(x)<<endl;
}
