#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int max1  = 0, start1 = -1, end1 = -1;
        int max2 = 0, start2 = -1;
        int start = 0;
        for(int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[start];
            if (diff <= 0) {
                start = i;
            } else if (diff > max1 && start != start1) {
                    max2 = max1;
                    start2 = start1;
                    max1 = diff;
                    start1 = start;
                    end1 = i;
            } else if (diff > max1) {
                max1 = diff;
                end1 = i;
            } else if (diff > max2 && start != start1) {
                max2 = diff;
                start2 = start;
            }
        }
        
        cout<<max1<<max2<<endl;
        if (max1 <= 0 && max2 <= 0)
            return 0;
        int max3 = 0; start = end1;
        for(int i = start-1; i>= start1; i--) {
            int diff = prices[i] - prices[start];
            if (diff <= 0)
                start = i;
            else if (diff > max3)
                max3 = diff;
        }
        if (max3 > max2)
            return max1+max3;
        return max1+max2;
    }
};

int main()
{
	vector<int> x {1,4,2};
Solution s;
cout<<s.maxProfit(x)<<endl;
}
