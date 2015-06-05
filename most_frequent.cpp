#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Solution {
public:
    class mycompare {
    public:
        bool operator()(const pair<int,int>& lhs, const pair<int,int>& rhs) {
            return lhs.first <= rhs.first;
        }
    };
    vector<int> mostFrequent(vector<int>& nums, int k)
    {
        map<int, int> freqs;
        for (int i = 0; i < nums.size(); i++) {
            auto x = freqs.insert(pair<int,int>(nums[i],1));
            if (!x.second)
                x.first->second++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, mycompare>pq;
        for(auto x = freqs.begin(); x != freqs.end(); x++) {
            if (pq.size() < k )
                pq.emplace(make_pair(x->first, x->second));
            else {
                if (x->second > pq.top().second) {
                    pq.pop();
                    pq.emplace(make_pair(x->first, x->second));
                }
            }
        }
        vector<int> ret;
        while(!pq.empty()) {
            ret.push_back(pq.top().first);
            pq.pop();
        }
        return ret;
    }
};
int main()
{
    Solution s;
    vector<int> x{3,1,2,3};
    vector<int> out = s.mostFrequent(x,1);
    for (int i = 0; i < out.size(); i++) {
        cout<<out[i]<<",";
    }
    cout<<endl;
}
