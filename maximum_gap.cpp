/*
Maximum Gap  
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

Credits:
Special thanks to @porker2008 for adding this problem and creating all test cases.
*/
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        int min = *min_element(nums.begin(), nums.end());
        int mymax = *max_element(nums.begin(), nums.end());
        int range = mymax - min;
        int nbuckets = nums.size();
        vector<int> mins(nbuckets, INT_MAX), maxs(nbuckets, INT_MIN);
        for(auto x : nums) {
            int index = ((double)(x-min)*(nbuckets-1))/range;
            if (mins[index] > x) mins[index] = x;
            if (maxs[index] < x) maxs[index] = x;
        }
        int prev = maxs[0];
        mymax = 0;
        for (int i = 1; i < nbuckets; i++) {
            if (mins[i] == INT_MAX) continue;
            mymax = max(mymax, mins[i]-prev);
            prev = maxs[i];
        }
        return mymax;
    }
};
