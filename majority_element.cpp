#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // moore's voting algorithm
        int maj = 0, count = 1;
        for(int i = 1; i < nums.size(); i++) {
            if (nums[i]==nums[maj])
                count++;
            else {
                count--;
                if (!count) {
                    count = 1;
                    maj = i;
                }
            }
        }
        // check if the element is actually a majority element
        count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i]==nums[maj])
                count++;
        }
        if (count >= nums.size()/2)
            return nums[maj];
        else
            return INT_MIN;
    }
};

int main()
{
	Solution s;
        int size;
	vector<int> x;// {2,3,4,5,6,1,4,4,1,1};
        cout<<"Enter the size of array\n";
        cin>>size;
        cout<<"Enter the array\n";
        for(int i = 0; i < size; i++) {
            int e;
            cin>>e;
            x.push_back(e);
        }
	cout<<s.majorityElement(x)<<endl;
}
